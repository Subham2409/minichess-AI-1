/*
test board.h
*/

#include "board_test.h"

void __Test__Board()
{
    MCError e;
    if ((e = TestGetSquare()) != mcet::NoErr)
    {
        std::cout << e.DisplayError() << std::endl;
    }
    if ((e = TestSetSquare()) != mcet::NoErr)
    {
        std::cout << e.DisplayError() << std::endl;
    }
    if ((e = TestSetBoardFEN()) != mcet::NoErr)
    {
        std::cout << e.DisplayError() << std::endl;
    }
    if ((e = TestIsChecked()) != mcet::NoErr)
    {
        std::cout << e.DisplayError() << std::endl;
    }
    if ((e = TestMove()) != mcet::NoErr)
    {
        std::cout << e.DisplayError() << std::endl;
    }
    if ((e = TestMoveForce()) != mcet::NoErr)
    {
        std::cout << e.DisplayError() << std::endl;
    }
}

// GetSquare
MCError TestGetSquare()
{
    Board b;

    if (b.GetSquare(Square{Square{AFILE, RANK1}}) != WKING)
        return mcet::genTestErr("GetSquare(Square{AFILE, RANK1}) is wrong");
    if (b.GetSquare(Square{BFILE, RANK1}) != WQUEEN)
        return mcet::genTestErr("GetSquare(Square{BFILE, RANK1}) is wrong");
    if (b.GetSquare(Square{CFILE, RANK1}) != WBISHOP)
        return mcet::genTestErr("GetSquare(Square{CFILE, RANK1}) is wrong");
    if (b.GetSquare(Square{DFILE, RANK1}) != WKNIGHT)
        return mcet::genTestErr("GetSquare(Square{DFILE, RANK1}) is wrong");
    if (b.GetSquare(Square{EFILE, RANK1}) != WROOK)
        return mcet::genTestErr("GetSquare(Square{EFILE, RANK1}) is wrong");
    for (File i = AFILE; i < EFILE; i++)
    {
        if (b.GetSquare(Square{i, RANK2}) != WPAWN)
            return mcet::genTestErr("GetSquare(" + std::to_string(static_cast<int>(i)) + ", RANK2) is wrong");
    }
    for (File i = AFILE; i < EFILE; i++)
    {
        if (b.GetSquare(Square{i, RANK3}) != EMPTYSQ)
            return mcet::genTestErr("GetSquare(" + std::to_string(static_cast<int>(i)) + ", RANK3) is wrong");
        if (b.GetSquare(Square{i, RANK4}) != EMPTYSQ)
            return mcet::genTestErr("GetSquare(" + std::to_string(static_cast<int>(i)) + ", RANK4) is wrong");
    }
    for (File i = AFILE; i < EFILE; i++)
    {
        if (b.GetSquare(Square{i, RANK5}) != BPAWN)
            return mcet::genTestErr("GetSquare(" + std::to_string(static_cast<int>(i)) + ", RANK5) is wrong");
    }
    if (b.GetSquare(Square{AFILE, RANK6}) != BROOK)
        return mcet::genTestErr("GetSquare(Square{6, 0}) is wrong");
    if (b.GetSquare(Square{BFILE, RANK6}) != BKNIGHT)
        return mcet::genTestErr("GetSquare(Square{6, 1}) is wrong");
    if (b.GetSquare(Square{CFILE, RANK6}) != BBISHOP)
        return mcet::genTestErr("GetSquare(Square{6, 2}) is wrong");
    if (b.GetSquare(Square{DFILE, RANK6}) != BQUEEN)
        return mcet::genTestErr("GetSquare(Square{6, 3}) is wrong");
    if (b.GetSquare(Square{EFILE, RANK6}) != BKING)
        return mcet::genTestErr("GetSquare(Square{6, 4}) is wrong");

    return mcet::NoErr;
}

// SetSquare
MCError TestSetSquare()
{
    Board b;
    b.SetSquare(Square{AFILE, RANK1}, WQUEEN);
    b.SetSquare(Square{BFILE, RANK2}, WKING);
    b.SetSquare(Square{CFILE, RANK3}, WPAWN);
    b.SetSquare(Square{DFILE, RANK4}, WBISHOP);
    b.SetSquare(Square{EFILE, RANK5}, WKNIGHT);
    b.SetSquare(Square{AFILE, RANK6}, WROOK);
    b.SetSquare(Square{BFILE, RANK6}, BQUEEN);
    b.SetSquare(Square{BFILE, RANK5}, BKING);
    b.SetSquare(Square{CFILE, RANK4}, BPAWN);
    b.SetSquare(Square{DFILE, RANK3}, BBISHOP);
    b.SetSquare(Square{EFILE, RANK2}, BKNIGHT);
    b.SetSquare(Square{EFILE, RANK1}, BROOK);
    b.SetSquare(Square{CFILE, RANK1}, EMPTYSQ);
    if (b.GetSquare(Square{AFILE, RANK1}) != WQUEEN)
        return mcet::genTestErr("SetSquare(Square{AFILE, RANK1},  WQUEEN) is wrong");
    if (b.GetSquare(Square{BFILE, RANK2}) != WKING)
        return mcet::genTestErr("SetSquare(Square{BFILE, RANK2},  WKING) is wrong");
    if (b.GetSquare(Square{CFILE, RANK3}) != WPAWN)
        return mcet::genTestErr("SetSquare(Square{CFILE, RANK3},  WPAWN) is wrong");
    if (b.GetSquare(Square{DFILE, RANK4}) != WBISHOP)
        return mcet::genTestErr("SetSquare(Square{DFILE, RANK4},  WBISHOP) is wrong");
    if (b.GetSquare(Square{EFILE, RANK5}) != WKNIGHT)
        return mcet::genTestErr("SetSquare(Square{EFILE, RANK5},  WKNIGHT) is wrong");
    if (b.GetSquare(Square{AFILE, RANK6}) != WROOK)
        return mcet::genTestErr("SetSquare(Square{AFILE, RANK6},  WROOK) is wrong");
    if (b.GetSquare(Square{BFILE, RANK6}) != BQUEEN)
        return mcet::genTestErr("SetSquare(Square{AFILE, RANK6},  WQUEEN) is wrong");
    if (b.GetSquare(Square{BFILE, RANK5}) != BKING)
        return mcet::genTestErr("SetSquare(Square{BFILE, RANK5},  WKING) is wrong");
    if (b.GetSquare(Square{CFILE, RANK4}) != BPAWN)
        return mcet::genTestErr("SetSquare(Square{CFILE, RANK4},  WPAWN) is wrong");
    if (b.GetSquare(Square{DFILE, RANK3}) != BBISHOP)
        return mcet::genTestErr("SetSquare(Square{DFILE, RANK3},  WBISHOP) is wrong");
    if (b.GetSquare(Square{EFILE, RANK2}) != BKNIGHT)
        return mcet::genTestErr("SetSquare(Square{EFILE, RANK2},  WKNIGHT) is wrong");
    if (b.GetSquare(Square{EFILE, RANK1}) != BROOK)
        return mcet::genTestErr("SetSquare(Square{AFILE, RANK1},  WROOK) is wrong");
    if (b.GetSquare(Square{CFILE, RANK1}) != EMPTYSQ)
        return mcet::genTestErr("SetSquare(Square{CFILE, RANK1},  EMPTYSQ) is wrong");

    return mcet::NoErr;
}

MCError TestSetBoardFEN()
{
    Board b;
    MCError e;

    // wrong FEN test

    // wrong piece placement (too many piece)
    if (b.SetBoardFEN("2bk1/pp1pp/n3pq/rRPPP/P4/KQBN1 w Kk d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong piece placement error due to too many piece doesn't work in SetBoardFEN");
    }
    // wrong piece placement (too many enpty squares)
    if (b.SetBoardFEN("2bk1/pp1pp/n2p2/rRPPP/P4/KQBN1 w Kk d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong piece placement error due to too many enpty squares doesn't work in SetBoardFEN");
    }
    // wrong piece placement (too many ranks)
    if (b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1/5 w Kk d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong piece placement error due to too many ranks doesn't work in SetBoardFEN");
    }
    // wrong piece placement (wrong character)
    if (b.SetBoardFEN("2bk1/pp1pp/n2vq/rRPPP/P4/KQBN1 w Kk d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong piece placement error due to wrong character doesn't work in SetBoardFEN");
    }
    // wrong color setting (wrong character)
    if (b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1 v Kk d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong color setting error due to wrong character doesn't work in SetBoardFEN");
    }
    // wrong color setting (too many color setting)
    if (b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1 wb Kk d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong color setting error due to too many color setting doesn't work in SetBoardFEN");
    }
    // wrong castling setting (wrong character)
    if (b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1 w Kc d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong castling setting error due to wrong character doesn't work in SetBoardFEN");
    }
    // wrong castling setting (overused characters)
    if (b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1 w KK d3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong castling setting error due to overuse of characters doesn't work in SetBoardFEN");
    }
    // wrong enpassant setting (wrong character)
    if (b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1 w Kk f3") != mcet::FENErr)
    {
        return mcet::genTestErr("Wrong enpassant setting error due to wrong character doesn't work in SetBoardFEN");
    }

    // no error test

    int *files;
    files = new int[5];

    // first

    if ((e = b.SetBoardFEN("2bk1/pp1pp/n2pq/rRPPP/P4/KQBN1 w Kk d3")) != mcet::NoErr)
    {
        return mcet::genTestErr("Unexpected error is returned : " + e.DisplayError());
    }

    files = b.GetBoard();
    if (
        (files[AFILE] != BPAWN * RANK5W + BKNIGHT * RANK4W + BROOK * RANK3W + WPAWN * RANK2W + WKING * RANK1W) ||
        (files[BFILE] != BPAWN * RANK5W + WROOK * RANK3W + WQUEEN * RANK1W) ||
        (files[CFILE] != BBISHOP * RANK6W + WPAWN * RANK3W + WBISHOP * RANK1W) ||
        (files[DFILE] != BKING * RANK6W + BPAWN * RANK5W + BPAWN * RANK4W + WPAWN * RANK3W + WKNIGHT * RANK1W) ||
        (files[EFILE] != BPAWN * RANK5W + BQUEEN * RANK4W + WPAWN * RANK3W))
    {
        return mcet::genTestErr("In SetBoardFEN, piece placement is wrong");
    }
    if (b.GetTurn() != cWhite)
    {
        return mcet::genTestErr("In SetBoardFEN, color setting is wrong");
    }
    if (b.GetCastlingPossibility(cWhite) != true || b.GetCastlingPossibility(cBlack) != true)
    {
        return mcet::genTestErr("In SetBoardFEN, castling possibility setting is wrong");
    }
    if (b.GetEnpassantAblePawnFile() != DFILE)
    {
        return mcet::genTestErr("In SetBoardFEN, enpassant setting is wrong");
    }

    // second

    if ((e = b.SetBoardFEN("3nk/1p1bq/pPpNr/B1P2/PKQ1p/4R b - -")) != mcet::NoErr)
    {
        return mcet::genTestErr("Unexpected error is returned : " + e.DisplayError());
    }

    files = b.GetBoard();
    if (
        (files[AFILE] != BPAWN * RANK4W + WBISHOP * RANK3W + WPAWN * RANK2W) ||
        (files[BFILE] != BPAWN * RANK5W + WPAWN * RANK4W + WKING * RANK2W) ||
        (files[CFILE] != BPAWN * RANK4W + WPAWN * RANK3W + WQUEEN * RANK2W) ||
        (files[DFILE] != BKNIGHT * RANK6W + BBISHOP * RANK5W + WKNIGHT * RANK4W) ||
        (files[EFILE] != BKING * RANK6W + BQUEEN * RANK5W + BROOK * RANK4W + BPAWN * RANK2W + WROOK * RANK1W))
    {
        return mcet::genTestErr("In SetBoardFEN, piece placement is wrong");
    }
    if (b.GetTurn() != cBlack)
    {
        return mcet::genTestErr("In SetBoardFEN, color setting is wrong");
    }
    if (b.GetCastlingPossibility(cWhite) != false || b.GetCastlingPossibility(cBlack) != false)
    {
        return mcet::genTestErr("In SetBoardFEN, castling possibility setting is wrong");
    }
    if (b.GetEnpassantAblePawnFile() != FILEERR)
    {
        return mcet::genTestErr("In SetBoardFEN, enpassant setting is wrong");
    }

    return mcet::NoErr;
}

MCError TestIsChecked()
{
    Board b;
    MCError e;

    // knight

    e = b.SetBoardFEN("3nk/1p1bq/pPpNr/B1P2/PKQ1p/4R w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in knight test case 1");
    e = b.SetBoardFEN("3K1/1kP2/2n1q/1p3/1P3/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in knight test case 2");
    e = b.SetBoardFEN("2N2/1nNkN/n1nNN/1NnN1/nNKnn/1n1n1 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in knight test case 3");
    e = b.SetBoardFEN("2k1N/p3r/1nP1p/pP2Q/P1K2/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in knight test case 4");
    e = b.SetBoardFEN("5/5/1q3/2kp1/N1bPp/K3R w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in knight test case 5");

    // bishop

    e = b.SetBoardFEN("1n3/k1p2/2Pp1/1K1Pp/3BP/4R w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in bishop test case 1");
    e = b.SetBoardFEN("3r1/1n3/k2Pb/p1P1P/2K2/3R1 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in bishop test case 2");
    e = b.SetBoardFEN("5/P4/2k1b/qN1n1/2KB1/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in bishop test case 3");
    e = b.SetBoardFEN("5/q4/2K2/5/bRpk1/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in bishop test case 4");
    e = b.SetBoardFEN("5/2k2/1nr1b/B2p1/3Q1/1KR2 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in bishop test case 5");

    // king

    e = b.SetBoardFEN("5/5/1Kk2/5/5/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in king test case 1");
    e = b.SetBoardFEN("k4/1K3/5/5/5/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in king test case 2");
    e = b.SetBoardFEN("5/5/5/5/4K/4k w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in king test case 3");
    e = b.SetBoardFEN("5/5/5/3K1/1k3/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in king test case 4");
    e = b.SetBoardFEN("5/3K1/5/3k1/5/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in king test case 5");

    // queen

    e = b.SetBoardFEN("r3k/1ppbq/p3p/1P3/PKPP1/1Q2R w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in queen test case 1");
    e = b.SetBoardFEN("r1b2/1k3/5/1pKQ1/pB3/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in queen test case 2");
    e = b.SetBoardFEN("5/2k2/5/2K1q/p2r1/2B2 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in queen test case 3");
    e = b.SetBoardFEN("3Q1/q3p/1n1kP/2N2/3K1/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in queen test case 4");
    e = b.SetBoardFEN("3K1/3Q1/2P2/1k3/4n/3q1 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in queen test case 5");

    // rook

    e = b.SetBoardFEN("3k1/1R3/2n2/2N2/5/1K1r1 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in rook test case 1");
    e = b.SetBoardFEN("2b2/2k2/1r1p1/1p1K1/1P2N/2R2 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in rook test case 2");
    e = b.SetBoardFEN("1N1B1/5/3P1/1krR1/5/2K2 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in rook test case 3");
    e = b.SetBoardFEN("3R1/5/3K1/5/3k1/3r1 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in rook test case 4");
    e = b.SetBoardFEN("2n2/1R2k/4r/BpK2/2PR1/4q w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in rook test case 5");

    // pawn

    e = b.SetBoardFEN("4k/3r1/2Pp1/2K2/qB3/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in pawn test case 1");
    e = b.SetBoardFEN("4k/1NpP1/1pP2/pPnp1/P4/K4 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in pawn test case 2");
    e = b.SetBoardFEN("5/2PpP/PPpKp/PkpPP/pPp2/5 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in pawn test case 3");
    e = b.SetBoardFEN("PPkPP/P1P1P/PPPPP/ppppp/p1p1p/ppKpp w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in pawn test case 4");
    e = b.SetBoardFEN("4P/3kr/1pp2/2K2/B1b2/4n w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in pawn test case 5");

    // random

    e = b.SetBoardFEN("rnbqk/2p1p/1p2P/1QPp1/P2P1/K1BNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in random test case 1");
    e = b.SetBoardFEN("rnbqk/4p/1pp1P/1QPp1/P2P1/K1BNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in random test case 2");
    e = b.SetBoardFEN("1r1kb/Q3p/3pq/P1n2/KP3/N2R1 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != true || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in random test case 3");
    e = b.SetBoardFEN("5/2k1p/Kp1r1/BP2Q/2b2/2R2 w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in random test case 4");
    e = b.SetBoardFEN("3k1/2PPr/3K1/5/p2nb/1qqqq b - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != true)
        return mcet::genTestErr("IsChecked is wrong in random test case 5");
    e = b.SetBoardFEN("ppKpp/ppppp/b1r1q/Q1R1B/PPPPP/PPkPP w - -");
    if (e != mcet::NoErr)
        return e;
    if (b.IsChecked(cWhite) != false || b.IsChecked(cBlack) != false)
        return mcet::genTestErr("IsChecked is wrong in random test case 6");

    return mcet::NoErr;
}

MCError TestMove()
{
    Board b, origin;
    MCError e;

    // illegals

    // wrong piece

    // white

    e = b.SetBoardFEN("rnbqk/4p/5/5/5/2K2 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK6}, Square{AFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 1");
    e = b.Move(Square{BFILE, RANK6}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 2");
    e = b.Move(Square{CFILE, RANK6}, Square{BFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 3");
    e = b.Move(Square{DFILE, RANK6}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 4");
    e = b.Move(Square{EFILE, RANK6}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 5");
    e = b.Move(Square{EFILE, RANK5}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 6");
    e = b.Move(Square{AFILE, RANK1}, Square{AFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 7");

    // black

    e = b.SetBoardFEN("2k2/5/5/5/P4/KQBNR b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK1}, Square{EFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 8");
    e = b.Move(Square{DFILE, RANK1}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 9 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 9");
    e = b.Move(Square{CFILE, RANK1}, Square{DFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 10 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 10");
    e = b.Move(Square{BFILE, RANK1}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 11 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 11");
    e = b.Move(Square{AFILE, RANK1}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 12 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 12");
    e = b.Move(Square{AFILE, RANK2}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 13 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 13");
    e = b.Move(Square{EFILE, RANK6}, Square{EFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveWPErr)
        return mcet::genTestErr("Move returns wrong error in wrong piece illegal test case 14 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in wrong piece illegal test case 14");

    // move to the same square

    // white

    e = b.SetBoardFEN("5/2k2/5/5/2K2/5 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK2}, Square{CFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in same square illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in same place illegal test case 1");

    // black

    e = b.SetBoardFEN("5/2k2/5/5/2K2/5 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in same square illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in same place illegal test case 2");

    // checked after move

    // already checked but don't avoid

    // white

    e = b.SetBoardFEN("2k2/4q/5/5/2PP1/KQBNR w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 1");
    e = b.Move(Square{BFILE, RANK1}, Square{AFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 2");
    e = b.Move(Square{CFILE, RANK1}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 3");
    e = b.Move(Square{DFILE, RANK1}, Square{EFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 4");
    e = b.Move(Square{EFILE, RANK1}, Square{EFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 5");
    e = b.Move(Square{CFILE, RANK2}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 6");
    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 7");

    // black

    e = b.SetBoardFEN("rnbqk/1pp2/5/5/Q4/2K2 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 8");
    e = b.Move(Square{DFILE, RANK6}, Square{EFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 9 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 9");
    e = b.Move(Square{CFILE, RANK6}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 10 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 10");
    e = b.Move(Square{BFILE, RANK6}, Square{AFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 11 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 11");
    e = b.Move(Square{AFILE, RANK6}, Square{AFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 12 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 12");
    e = b.Move(Square{CFILE, RANK5}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 13 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 13");
    e = b.Move(Square{BFILE, RANK5}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 14 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 14");

    // not checked before move

    // white

    e = b.SetBoardFEN("2k2/4q/5/5/1R3/K4 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{BFILE, RANK2}, Square{CFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 15 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 15");

    // black

    e = b.SetBoardFEN("4k/3r1/5/5/Q4/2K2 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{DFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in checked after move illegal test case 16 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in checked after move illegal test case 16");

    // move to the square with a same color piece

    // white

    e = b.SetBoardFEN("4k/5/1P3/1pP2/1B3/KQRN1 w - b3");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 1");
    e = b.Move(Square{BFILE, RANK1}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 2");
    e = b.Move(Square{BFILE, RANK2}, Square{AFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 3");
    e = b.Move(Square{CFILE, RANK1}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 4");
    e = b.Move(Square{CFILE, RANK3}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 5");
    e = b.Move(Square{DFILE, RANK1}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 6");

    // black

    e = b.SetBoardFEN("1nrqk/3b1/2pP1/3p1/5/K4 b - d4");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 7");
    e = b.Move(Square{DFILE, RANK6}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 8");
    e = b.Move(Square{DFILE, RANK5}, Square{EFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 9 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 9");
    e = b.Move(Square{CFILE, RANK6}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 10 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 10");
    e = b.Move(Square{CFILE, RANK4}, Square{DFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 11 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 11");
    e = b.Move(Square{BFILE, RANK6}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error take same color piece illegal test case 12 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in take same color piece illegal tes case 12");

    // pawn

    // white

    // e3 is q but it has meanings
    e = b.SetBoardFEN("rnbqk/p3p/1p3/2pPq/PPP1P/KQBNR w - e3");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK2}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 1");
    e = b.Move(Square{CFILE, RANK2}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 2");
    e = b.Move(Square{BFILE, RANK2}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 3");
    e = b.Move(Square{DFILE, RANK3}, Square{DFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 4");
    e = b.Move(Square{DFILE, RANK3}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 5");
    e = b.Move(Square{DFILE, RANK3}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 6");
    e = b.Move(Square{AFILE, RANK2}, Square{BFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 7");
    e = b.Move(Square{AFILE, RANK2}, Square{BFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 8");
    e = b.Move(Square{AFILE, RANK2}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn illegal test case 9 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn illegal test case 9");

    // black

    // a4 is Q but it has meanings
    e = b.SetBoardFEN("rnbqk/p1ppp/QpP2/3P1/P3P/KQBNR b - a4");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK5}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 1");
    e = b.Move(Square{CFILE, RANK5}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 2");
    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 3");
    e = b.Move(Square{BFILE, RANK4}, Square{BFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 4");
    e = b.Move(Square{BFILE, RANK4}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 5");
    e = b.Move(Square{BFILE, RANK4}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 6");
    e = b.Move(Square{EFILE, RANK5}, Square{DFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 7");
    e = b.Move(Square{EFILE, RANK5}, Square{DFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 8");
    e = b.Move(Square{EFILE, RANK5}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn illegal test case 9 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn illegal test case 9");

    // promotion

    // white

    e = b.SetBoardFEN("5/1k1P1/5/5/1K1p1/5 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn promotion illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn promotion illegal test case 1");
    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK6}, WPAWN);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn promotion illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn promotion illegal test case 2");
    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK6}, WKING);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn promotion illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn promotion illegal test case 3");
    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK6}, BBISHOP);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn promotion illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn promotion illegal test case 4");
    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK6}, BPAWN);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white pawn promotion illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white pawn promotion illegal test case 5");

    // black

    e = b.SetBoardFEN("5/1k1P1/5/5/1K1p1/5 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn promotion illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn promotion illegal test case 1");
    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK1}, BPAWN);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn promotion illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn promotion illegal test case 2");
    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK1}, BKING);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn promotion illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn promotion illegal test case 3");
    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK1}, WBISHOP);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn promotion illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn promotion illegal test case 4");
    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK1}, WPAWN);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black pawn promotion illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black pawn promotion illegal test case 5");

    // king

    // white

    e = b.SetBoardFEN("2k2/5/5/5/5/K2NR w K -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 1");

    e = b.SetBoardFEN("2k2/r4/5/5/5/K3R w K -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 2");

    e = b.SetBoardFEN("2k2/1r3/5/5/5/K3R w K -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 3");

    e = b.SetBoardFEN("2k2/2r2/5/5/5/K3R w K -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 4");

    e = b.SetBoardFEN("2k2/5/5/5/5/K3R w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 5");

    e = b.SetBoardFEN("2k2/5/5/2K2/5/5 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 6");

    e = b.SetBoardFEN("2k2/5/5/2K2/5/5 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 7");

    e = b.SetBoardFEN("2k2/5/5/2K2/5/5 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white king illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white king illegal test case 8");

    // black

    e = b.SetBoardFEN("rn2k/5/5/5/5/2K2 b k -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 1");

    e = b.SetBoardFEN("r3k/5/5/5/4R/2K2 b k -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 2");

    e = b.SetBoardFEN("r3k/5/5/5/3R1/2K2 b k -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 3");

    e = b.SetBoardFEN("r3k/5/5/5/2R2/2K2 b k -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 4 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 4");

    e = b.SetBoardFEN("r3k/5/5/5/5/2K2 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 5 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 5");

    e = b.SetBoardFEN("5/5/2k2/5/5/2K2 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 6 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 6");

    e = b.SetBoardFEN("5/5/2k2/5/5/2K2 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 7 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 7");

    e = b.SetBoardFEN("5/5/2k2/5/5/2K2 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black king illegal test case 8 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black king illegal test case 8");

    // queen

    // white

    e = b.SetBoardFEN("4k/5/3P1/1pQ2/5/K4 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white queen illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white queen illegal test case 1");
    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white queen illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white queen illegal test case 2");
    e = b.Move(Square{CFILE, RANK3}, Square{AFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white queen illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white queen illegal test case 3");

    // black

    e = b.SetBoardFEN("4k/5/2qP1/1p3/5/K4 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black queen illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black queen illegal test case 1");
    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black queen illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black queen illegal test case 2");
    e = b.Move(Square{CFILE, RANK4}, Square{EFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black queen illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black queen illegal test case 3");

    // rook

    // white

    e = b.SetBoardFEN("4k/5/5/1pR2/2P2/K4 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white rook illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white rook illegal test case 1");
    e = b.Move(Square{CFILE, RANK3}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white rook illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white rook illegal test case 2");
    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white rook illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white rook illegal test case 3");

    // black

    e = b.SetBoardFEN("4k/2p2/2rP1/5/5/K4 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black rook illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black rook illegal test case 1");
    e = b.Move(Square{CFILE, RANK4}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black rook illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black rook illegal test case 2");
    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black rook illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black rook illegal test case 3");

    // bishop

    // white

    e = b.SetBoardFEN("4k/5/3r1/2B2/3N1/K4 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white bishop illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white bishop illegal test case 1");
    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white bishop illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white bishop illegal test case 2");
    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white bishop illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white bishop illegal test case 3");

    // black

    e = b.SetBoardFEN("4k/1n3/2b2/1R3/5/K4 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black bishop illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black bishop illegal test case 1");
    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black bishop illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black bishop illegal test case 2");
    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black bishop illegal test case 3 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black bishop illegal test case 3");

    // knight

    // white

    e = b.SetBoardFEN("4k/5/5/2N2/5/K4 w - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK3}, Square{EFILE, RANK1}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white knight illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white knight illegal test case 1");
    e = b.Move(Square{CFILE, RANK3}, Square{CFILE, RANK5}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in white knight illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in white knight illegal test case 2");

    // black

    e = b.SetBoardFEN("4k/5/2n2/5/5/K4 b - -");
    if (e != mcet::NoErr)
        return e;

    origin = b;

    e = b.Move(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black knight illegal test case 1 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black knight illegal test case 1");
    e = b.Move(Square{CFILE, RANK4}, Square{CFILE, RANK2}, EMPTYSQ);
    if (e != mcet::MoveErr)
        return mcet::genTestErr("Move returns wrong error in black knight illegal test case 2 : " + e.DisplayError());
    if (origin != b)
        return mcet::genTestErr("Move is wrong in black knight illegal test case 2");

    // legals

    Board corb;

    // castling

    // white

    e = b.SetBoardFEN("2k2/3r1/5/5/1P3/K3R w Kk -");
    if (e != mcet::NoErr)
        return e;

    e = b.Move(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in white castling test case 1 : " + e.DisplayError());
    e = corb.SetBoardFEN("2k2/3r1/5/5/1P3/1RK2 b k -");
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in white castling test case 1");

    // black

    e = b.SetBoardFEN("r3k/3p1/5/5/1R3/2K2 b Kk -");
    if (e != mcet::NoErr)
        return e;

    e = b.Move(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in black castling test case 1 : " + e.DisplayError());
    e = corb.SetBoardFEN("2kr1/3p1/5/5/1R3/2K2 w K -");
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in black castling test case 1");

    // play game

    b.InitBoard();

    e = b.Move(Square{EFILE, RANK2}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 1. e4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppppp/4P/5/PPPP1/KQBNR b Kk e4");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 1. e4");

    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 1. ... d4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppp1p/3pP/5/PPPP1/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 1. ... d4");

    e = b.Move(Square{BFILE, RANK2}, Square{BFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 2. b3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppp1p/3pP/1P3/P1PP1/KQBNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 2. b3");

    e = b.Move(Square{AFILE, RANK5}, Square{AFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 2. ... a4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/1pp1p/p2pP/1P3/P1PP1/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 2. ... a4");

    e = b.Move(Square{BFILE, RANK3}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 3. b4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/1pp1p/pP1pP/5/P1PP1/KQBNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 3. b4");

    e = b.Move(Square{CFILE, RANK5}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 3. ... cxb4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/1p2p/pp1pP/5/P1PP1/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 3. ... cxb4");

    e = b.Move(Square{AFILE, RANK2}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 4. a3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/1p2p/pp1pP/P4/2PP1/KQBNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 4. a3");

    e = b.Move(Square{BFILE, RANK6}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 4. ... Nc4 : " + e.DisplayError());
    e = corb.SetBoardFEN("r1bqk/1p2p/ppnpP/P4/2PP1/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 4. ... Nc4");

    e = b.Move(Square{AFILE, RANK3}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 5. axb4 : " + e.DisplayError());
    e = corb.SetBoardFEN("r1bqk/1p2p/pPnpP/5/2PP1/KQBNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 5. axb4");

    e = b.Move(Square{AFILE, RANK4}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 5. ... a3 : " + e.DisplayError());
    e = corb.SetBoardFEN("r1bqk/1p2p/1PnpP/p4/2PP1/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 5. ... a3");

    e = b.Move(Square{BFILE, RANK1}, Square{BFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 6. Qb3 : " + e.DisplayError());
    e = corb.SetBoardFEN("r1bqk/1p2p/1PnpP/pQ3/2PP1/K1BNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 6. Qb3");

    e = b.Move(Square{AFILE, RANK3}, Square{AFILE, RANK2}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 6. ... a2 : " + e.DisplayError());
    e = corb.SetBoardFEN("r1bqk/1p2p/1PnpP/1Q3/p1PP1/K1BNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 6. ... a2");

    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 7. d3 : " + e.DisplayError());
    e = corb.SetBoardFEN("r1bqk/1p2p/1PnpP/1Q1P1/p1P2/K1BNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 7. d3");

    e = b.Move(Square{AFILE, RANK6}, Square{AFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 7. ... Ra4 : " + e.DisplayError());
    e = corb.SetBoardFEN("2bqk/1p2p/rPnpP/1Q1P1/p1P2/K1BNR w K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 7. ... Ra4");

    e = b.Move(Square{DFILE, RANK3}, Square{CFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 8. dxc4 : " + e.DisplayError());
    e = corb.SetBoardFEN("2bqk/1p2p/rPPpP/1Q3/p1P2/K1BNR b K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 8. dxc4");

    e = b.Move(Square{AFILE, RANK4}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 8. ... Rxb4 : " + e.DisplayError());
    e = corb.SetBoardFEN("2bqk/1p2p/1rPpP/1Q3/p1P2/K1BNR w K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 8. ... Rxb4");

    e = b.Move(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 9. c5+ : " + e.DisplayError());
    e = corb.SetBoardFEN("2bqk/1pP1p/1r1pP/1Q3/p1P2/K1BNR b K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 9. c5+");

    e = b.Move(Square{BFILE, RANK4}, Square{BFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 9. ... Rxb4 : " + e.DisplayError());
    e = corb.SetBoardFEN("2bqk/1pP1p/3pP/1r3/p1P2/K1BNR w K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 9. ... Rxb4");

    e = b.Move(Square{CFILE, RANK5}, Square{DFILE, RANK6}, WQUEEN);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 10. cxd6=Q+ : " + e.DisplayError());
    e = corb.SetBoardFEN("2bQk/1p2p/3pP/1r3/p1P2/K1BNR b K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 10. cxd6=Q+");

    e = b.Move(Square{EFILE, RANK6}, Square{DFILE, RANK6}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move return unexpected error in play game test case 1 : 10. ... Kxd6 : " + e.DisplayError());
    e = corb.SetBoardFEN("2bk1/1p2p/3pP/1r3/p1P2/K1BNR w K -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 1 : 10. ... Kxd6");

    // first game end

    b.InitBoard();

    e = b.Move(Square{BFILE, RANK2}, Square{BFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 1. b3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppppp/5/1P3/P1PPP/KQBNR b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 1. b3");

    e = b.Move(Square{DFILE, RANK5}, Square{DFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 1. ... d4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppp1p/3p1/1P3/P1PPP/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 1. ... d4");

    e = b.Move(Square{EFILE, RANK2}, Square{EFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 2. e4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppp1p/3pP/1P3/P1PP1/KQBNR b Kk e3");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 2. e4");

    e = b.Move(Square{DFILE, RANK4}, Square{EFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 2. ... dxe3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppp1p/5/1P2p/P1PP1/KQBNR w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 2. ... dxe3");

    e = b.Move(Square{DFILE, RANK1}, Square{EFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 3. Nxe3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/ppp1p/5/1P2N/P1PP1/KQB1R b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 3. Nxe3");

    e = b.Move(Square{AFILE, RANK5}, Square{AFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 3. ... a3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/1pp1p/5/pP2N/P1PP1/KQB1R w Kk a4");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 3. ... a3");

    e = b.Move(Square{DFILE, RANK2}, Square{DFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 4. d3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/1pp1p/5/pP1PN/P1P2/KQB1R b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 4. d3");

    e = b.Move(Square{BFILE, RANK5}, Square{BFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 4. ... b4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/2p1p/1p3/pP1PN/P1P2/KQB1R w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 4. ... b4");

    e = b.Move(Square{CFILE, RANK2}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 5. c3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/2p1p/1p3/pPPPN/P4/KQB1R b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 5. c3");

    e = b.Move(Square{BFILE, RANK4}, Square{CFILE, RANK3}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 5. ... bxc3 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/2p1p/5/pPpPN/P4/KQB1R w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 5. ... bxc3");

    e = b.Move(Square{BFILE, RANK1}, Square{CFILE, RANK2}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 6. Qc2 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnbqk/2p1p/5/pPpPN/P1Q2/K1B1R b Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 6. Qc2");

    e = b.Move(Square{DFILE, RANK6}, Square{DFILE, RANK4}, EMPTYSQ);
    if (e != mcet::NoErr)
        return mcet::genTestErr("Move returns unexpected error in play game test case 2 : 6. ... Qd4 : " + e.DisplayError());
    e = corb.SetBoardFEN("rnb1k/2p1p/3q1/pPpPN/P1Q2/K1B1R w Kk -");
    if (e != mcet::NoErr)
        return e;
    if (b != corb)
        return mcet::genTestErr("Move doesn't work correctly in play game test case 2 : 6. ... Qd4");

    return mcet::NoErr;
}

MCError TestMoveForce()
{

    Board b, origin, corb;
    MCError e;

    // Normal Move
    b.SetBoardFEN("5/5/2K2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/1K3/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king normal move 1");
    }
    b.SetBoardFEN("5/5/1K3/5/5/5 w - -");
    b.MoveForce(Square{BFILE, RANK4}, Square{BFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/1K3/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king normal move 2");
    }
    b.SetBoardFEN("5/1K3/5/5/5/5 w - -");
    b.MoveForce(Square{BFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2K2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king normal move 3");
    }
    b.SetBoardFEN("5/5/2k2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/1k3/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king normal move 1");
    }
    b.SetBoardFEN("5/5/1k3/5/5/5 b - -");
    b.MoveForce(Square{BFILE, RANK4}, Square{BFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/1k3/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king normal move 2");
    }
    b.SetBoardFEN("5/1k3/5/5/5/5 b - -");
    b.MoveForce(Square{BFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2k2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king normal move 3");
    }
    b.SetBoardFEN("5/5/2P2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2P2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn normal move");
    }
    b.SetBoardFEN("5/5/2p2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2p2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn normal move");
    }
    b.SetBoardFEN("5/5/2N2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("1N3/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white knight normal move 1");
    }
    b.SetBoardFEN("1N3/5/5/5/5/5 w - -");
    b.MoveForce(Square{BFILE, RANK6}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/N4/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white knight normal move 2");
    }
    b.SetBoardFEN("5/5/N4/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2N2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white knight normal move 3");
    }
    b.SetBoardFEN("5/5/2n2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("1n3/5/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black knight normal move 1");
    }
    b.SetBoardFEN("1n3/5/5/5/5/5 b - -");
    b.MoveForce(Square{BFILE, RANK6}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/n4/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black knight normal move 2");
    }
    b.SetBoardFEN("5/5/n4/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2n2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black knight normal move 3");
    }
    b.SetBoardFEN("5/5/2B2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("B4/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white bishop normal move 1");
    }
    b.SetBoardFEN("B4/5/5/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK6}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/4B/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white bishop normal move 2");
    }
    b.SetBoardFEN("5/5/5/5/4B/5 w - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{DFILE, RANK1}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/5/3B1 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white bishop normal move 3");
    }
    b.SetBoardFEN("5/5/2b2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("b4/5/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black bishop normal move 1");
    }
    b.SetBoardFEN("b4/5/5/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK6}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/4b/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black bishop normal move 2");
    }
    b.SetBoardFEN("5/5/5/5/4b/5 b - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{DFILE, RANK1}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/5/3b1 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black bishop normal move 3");
    }
    b.SetBoardFEN("5/5/2R2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/R4/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook normal move 1");
    }
    b.SetBoardFEN("5/5/R4/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{AFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/R4/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook normal move 2");
    }
    b.SetBoardFEN("5/R4/5/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2R2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook normal move 3");
    }
    b.SetBoardFEN("5/5/2r2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/r4/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook normal move 1");
    }
    b.SetBoardFEN("5/5/r4/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{AFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/r4/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook normal move 2");
    }
    b.SetBoardFEN("5/r4/5/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2r2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook normal move 3");
    }
    b.SetBoardFEN("5/5/2Q2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/4Q/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white queen normal move 1");
    }
    b.SetBoardFEN("5/5/5/5/4Q/5 w - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{EFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/4Q/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white queen normal move 2");
    }
    b.SetBoardFEN("5/4Q/5/5/5/5 w - -");
    b.MoveForce(Square{EFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2Q2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white queen normal move 3");
    }
    b.SetBoardFEN("5/5/2q2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/4q/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black queen normal move 1");
    }
    b.SetBoardFEN("5/5/5/5/4q/5 b - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{EFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/4q/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black queen normal move 2");
    }
    b.SetBoardFEN("5/4q/5/5/5/5 b - -");
    b.MoveForce(Square{EFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2q2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black queen normal move 3");
    }

    // lose Castling move
    b.SetBoardFEN("5/5/2K2/5/5/5 w Kk -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2K2/5/5/5/5 b k -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king lose Castling move 1");
    }
    b.SetBoardFEN("5/5/2k2/5/5/5 b Kk -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2k2/5/5/5/5 w K -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king lose Castling move 1");
    }
    b.SetBoardFEN("5/5/2K2/5/5/5 w K -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2K2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king lose Castling move 2");
    }
    b.SetBoardFEN("5/5/2k2/5/5/5 b k -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2k2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king lose Castling move 2");
    }
    b.SetBoardFEN("5/5/2R2/5/5/5 w Kk -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2R2/5/5/5/5 b k -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook lose Castling move 1");
    }
    b.SetBoardFEN("5/5/2r2/5/5/5 b Kk -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2r2/5/5/5/5 w K -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook lose Castling move 1");
    }
    b.SetBoardFEN("5/5/2R2/5/5/5 w K -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2R2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook lose Castling move 2");
    }
    b.SetBoardFEN("5/5/2r2/5/5/5 b k -");
    b.MoveForce(Square{CFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2r2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook lose Castling move 2");
    }
    b.SetBoardFEN("5/5/5/5/5/K3R w Kk -");
    b.MoveForce(Square{AFILE, RANK1}, Square{CFILE, RANK1}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/5/1RK2 b k -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king Castling move 1");
    }
    b.SetBoardFEN("r3k/5/5/5/5/5 b Kk -");
    b.MoveForce(Square{EFILE, RANK6}, Square{CFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("2kr1/5/5/5/5/5 w K -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king Castling move 1");
    }
    //コード的にキャスリング権失うのが同じとこで動いてるからKk->kが動いてればOK

    // pawn double move
    b.SetBoardFEN("5/5/5/5/PPPPP/5 w - -");
    b.MoveForce(Square{CFILE, RANK2}, Square{CFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/2P2/5/PP1PP/5 b - c5");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn double move 1");
    }
    b.SetBoardFEN("5/ppppp/5/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK5}, Square{CFILE, RANK3}, EMPTYSQ);
    corb.SetBoardFEN("5/pp1pp/5/2p2/5/5 w - c4");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn double move 1");
    }
    b.SetBoardFEN("5/5/5/5/PPPPP/5 w - -");
    b.MoveForce(Square{AFILE, RANK2}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/P4/5/1PPPP/5 b - a5");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn double move 2");
    }
    b.SetBoardFEN("5/ppppp/5/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK5}, Square{AFILE, RANK3}, EMPTYSQ);
    corb.SetBoardFEN("5/1pppp/5/p4/5/5 w - a4");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn double move 2");
    }

    // take move
    b.SetBoardFEN("5/1pp2/1pK2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/1pp2/1K3/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king take move 1");
    }
    b.SetBoardFEN("5/1pp2/1K3/5/5/5 w - -");
    b.MoveForce(Square{BFILE, RANK4}, Square{BFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/1Kp2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king take move 2");
    }
    b.SetBoardFEN("5/1Kp2/5/5/5/5 w - -");
    b.MoveForce(Square{BFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2K2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white king take move 3");
    }
    b.SetBoardFEN("5/1PP2/1Pk2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/1PP2/1k3/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king take move 1");
    }
    b.SetBoardFEN("5/1PP2/1k3/5/5/5 b - -");
    b.MoveForce(Square{BFILE, RANK4}, Square{BFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/1kP2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king take move 2");
    }
    b.SetBoardFEN("5/1kP2/5/5/5/5 b - -");
    b.MoveForce(Square{BFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2k2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black king take move 3");
    }
    b.SetBoardFEN("5/1p3/2P2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/1P3/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn take move");
    }
    b.SetBoardFEN("5/1P3/2p2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/1p3/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn take move");
    }
    b.SetBoardFEN("1p3/2p2/p1N2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("1N3/2p2/p4/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white knight take move 1");
    }
    b.SetBoardFEN("1N3/2p2/p4/5/5/5 w - -");
    b.MoveForce(Square{BFILE, RANK6}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/2p2/N4/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white knight take move 2");
    }
    b.SetBoardFEN("5/2p2/N4/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2N2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white knight take move 3");
    }
    b.SetBoardFEN("1P3/2P2/P1n2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("1n3/2P2/P4/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black knight take move 1");
    }
    b.SetBoardFEN("1n3/2P2/P4/5/5/5 b - -");
    b.MoveForce(Square{BFILE, RANK6}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/2P2/n4/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black knight take move 2");
    }
    b.SetBoardFEN("5/2P2/n4/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2n2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black knight take move 3");
    }
    b.SetBoardFEN("p4/5/2B2/5/4p/3p1 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("B4/5/5/5/4p/3p1 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white bishop take move 1");
    }
    b.SetBoardFEN("B4/5/5/5/4p/3p1 w - -");
    b.MoveForce(Square{AFILE, RANK6}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/4B/3p1 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white bishop take move 2");
    }
    b.SetBoardFEN("5/5/5/5/4B/3p1 w - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{DFILE, RANK1}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/5/3B1 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white bishop take move 3");
    }
    b.SetBoardFEN("P4/5/2b2/5/4P/3P1 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK6}, EMPTYSQ);
    corb.SetBoardFEN("b4/5/5/5/4P/3P1 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black bishop take move 1");
    }
    b.SetBoardFEN("b4/5/5/5/4P/3P1 b - -");
    b.MoveForce(Square{AFILE, RANK6}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/4b/3P1 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black bishop take move 2");
    }
    b.SetBoardFEN("5/5/5/5/4b/3P1 b - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{DFILE, RANK1}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/5/5/3b1 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black bishop take move 3");
    }
    b.SetBoardFEN("5/p1p2/p1R2/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/p1p2/R4/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook take move 1");
    }
    b.SetBoardFEN("5/p1p2/R4/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{AFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/R1p2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook take move 2");
    }
    b.SetBoardFEN("5/R1p2/5/5/5/5 w - -");
    b.MoveForce(Square{AFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2R2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white rook take move 3");
    }
    b.SetBoardFEN("5/P1P2/P1r2/5/5/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{AFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/P1P2/r4/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook take move 1");
    }
    b.SetBoardFEN("5/P1P2/r4/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK4}, Square{AFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/r1P2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook take move 2");
    }
    b.SetBoardFEN("5/r1P2/5/5/5/5 b - -");
    b.MoveForce(Square{AFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2r2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black rook take move 3");
    }
    b.SetBoardFEN("5/2p1p/2Q2/5/4p/5 w - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/2p1p/5/5/4Q/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white queen take move 1");
    }
    b.SetBoardFEN("5/2p1p/5/5/4Q/5 w - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{EFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2p1Q/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white queen take move 2");
    }
    b.SetBoardFEN("5/2p1Q/5/5/5/5 w - -");
    b.MoveForce(Square{EFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2Q2/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white queen take move 3");
    }
    b.SetBoardFEN("5/2P1P/2q2/5/4P/5 b - -");
    b.MoveForce(Square{CFILE, RANK4}, Square{EFILE, RANK2}, EMPTYSQ);
    corb.SetBoardFEN("5/2P1P/5/5/4q/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black queen take move 1");
    }
    b.SetBoardFEN("5/2P1P/5/5/4q/5 b - -");
    b.MoveForce(Square{EFILE, RANK2}, Square{EFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2P1q/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black queen take move 2");
    }
    b.SetBoardFEN("5/2P1q/5/5/5/5 b - -");
    b.MoveForce(Square{EFILE, RANK5}, Square{CFILE, RANK5}, EMPTYSQ);
    corb.SetBoardFEN("5/2q2/5/5/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black queen take move 3");
    }

    // anpassant take move
    b.SetBoardFEN("5/5/5/1pP2/5/5 w - b");
    b.MoveForce(Square{CFILE, RANK3}, Square{BFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/1P3/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn anppasant take move 1");
    }
    b.SetBoardFEN("5/5/1Pp2/5/5/5 b - b");
    b.MoveForce(Square{CFILE, RANK4}, Square{BFILE, RANK3}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/1p3/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn anppasant take move 1");
    }
    b.SetBoardFEN("5/5/5/3Pp/5/5 w - e");
    b.MoveForce(Square{DFILE, RANK3}, Square{EFILE, RANK4}, EMPTYSQ);
    corb.SetBoardFEN("5/5/4P/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn anppasant take move 2");
    }
    b.SetBoardFEN("5/5/3pP/5/5/5 b - e");
    b.MoveForce(Square{DFILE, RANK4}, Square{EFILE, RANK3}, EMPTYSQ);
    corb.SetBoardFEN("5/5/5/4p/5/5 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn anppasant take move 2");
    }

    // promotion move
    b.SetBoardFEN("5/2P2/5/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK5}, Square{CFILE, RANK6}, WQUEEN);
    corb.SetBoardFEN("2Q2/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn promotion move 1");
    }
    b.SetBoardFEN("5/5/5/5/2p2/5 b - -");
    b.MoveForce(Square{CFILE, RANK2}, Square{CFILE, RANK1}, BQUEEN);
    corb.SetBoardFEN("5/5/5/5/5/2q2 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn promotion move 1");
    }
    b.SetBoardFEN("5/2P2/5/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK5}, Square{CFILE, RANK6}, WROOK);
    corb.SetBoardFEN("2R2/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn promotion move 2");
    }
    b.SetBoardFEN("5/5/5/5/2p2/5 b - -");
    b.MoveForce(Square{CFILE, RANK2}, Square{CFILE, RANK1}, BROOK);
    corb.SetBoardFEN("5/5/5/5/5/2r2 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn promotion move 2");
    }
    b.SetBoardFEN("5/2P2/5/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK5}, Square{CFILE, RANK6}, WBISHOP);
    corb.SetBoardFEN("2B2/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn promotion move 3");
    }
    b.SetBoardFEN("5/5/5/5/2p2/5 b - -");
    b.MoveForce(Square{CFILE, RANK2}, Square{CFILE, RANK1}, BBISHOP);
    corb.SetBoardFEN("5/5/5/5/5/2b2 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn promotion move 3");
    }
    b.SetBoardFEN("5/2P2/5/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK5}, Square{CFILE, RANK6}, WKNIGHT);
    corb.SetBoardFEN("2N2/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn promotion move 4");
    }
    b.SetBoardFEN("5/5/5/5/2p2/5 b - -");
    b.MoveForce(Square{CFILE, RANK2}, Square{CFILE, RANK1}, BKNIGHT);
    corb.SetBoardFEN("5/5/5/5/5/2n2 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn promotion move 4");
    }
    b.SetBoardFEN("1p3/2P2/5/5/5/5 w - -");
    b.MoveForce(Square{CFILE, RANK5}, Square{BFILE, RANK6}, WQUEEN);
    corb.SetBoardFEN("1Q3/5/5/5/5/5 b - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in white pawn promotion move 5");
    }
    b.SetBoardFEN("5/5/5/5/2p2/1P3 b - -");
    b.MoveForce(Square{CFILE, RANK2}, Square{BFILE, RANK1}, BQUEEN);
    corb.SetBoardFEN("5/5/5/5/5/1q3 w - -");
    if (b != corb)
    {
        return mcet::genTestErr("MoveForce doesn't work correctly in black pawn promotion move 5");
    }

    return mcet::NoErr;
}