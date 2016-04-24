#include "slp.h"

//Example program 1
// a:=5+3; b := (print(a, a-1), 10*a); print(b);
CompoundStm	prog1 = 
CompoundStm(new AssignStm("a",new OpExp(new NumExp(5), OpExp::PLUS, 
					    new NumExp(3))),
 new CompoundStm(new AssignStm("b",
     new EseqExp(new PrintStm(new PairExpList(new IdExp("a"),
                       new LastExpList(new OpExp(new IdExp("a"), OpExp::MINUS,
				  	         new NumExp(1))))),
             new OpExp(new NumExp(10), OpExp::TIMES, new IdExp("a")))),
  new PrintStm(new LastExpList(new IdExp("b")))));

//Example program 2
// a:=7; print(a, (print(2*a, (a:=a+1,a)), a))
CompoundStm prog2 =
CompoundStm(new AssignStm("a", new NumExp(7)),
		new PrintStm(new PairExpList(new IdExp("a"),
  new LastExpList(new EseqExp(new PrintStm(new PairExpList(
  new OpExp(new NumExp(2), OpExp::TIMES, new IdExp("a")),
  new LastExpList(new EseqExp(new AssignStm("a",
  new OpExp(new IdExp("a"), OpExp::PLUS, new NumExp(1))),
  new IdExp("a"))))), new IdExp("a"))))));

// Produces the following output:
// 7 14 8
// 8


//Example program 3
// print(
//   (a:=3, (print((b:=a-1, a)), b*3)),
//   a*3,
//   (c:=a*b,c)
// )
PrintStm prog3 =
PrintStm(
  new PairExpList(
    new EseqExp(
      new AssignStm("a", new NumExp(3)),
      new EseqExp(
        new PrintStm(
	  new LastExpList(
	    new EseqExp(
	      new AssignStm("b", new OpExp(new IdExp("a"),
					   OpExp::MINUS,
					   new NumExp(1))),
	      new IdExp("a")))),
	new OpExp(new IdExp("b"), OpExp::TIMES, new NumExp(3)))),
  new PairExpList(
    new OpExp(new IdExp("a"), OpExp::TIMES, new NumExp(3)),
  new LastExpList(
    new EseqExp(
      new AssignStm("c", new OpExp(new IdExp("a"),
				   OpExp::TIMES,
				   new IdExp("b"))),
      new IdExp("c"))))));

// Produces the following output:
// 3
// 6 9 6

//Example program 4
// a:=7; b:=(a:=a+2,a)*(a:=a-3,a); print(a,b)
CompoundStm prog4 =
CompoundStm( new AssignStm("a", new NumExp(7)),
  new CompoundStm(new AssignStm("b",
  new OpExp(new EseqExp(new AssignStm("a",
  new OpExp(new IdExp("a"), OpExp::PLUS, new NumExp(2))), new IdExp("a")),
  OpExp::TIMES,
  new EseqExp(new AssignStm("a",
  new OpExp(new IdExp("a"), OpExp::MINUS, new NumExp(3))), new IdExp("a")))),
  new PrintStm(new PairExpList(new IdExp("a"),
  new LastExpList(new IdExp("b"))))));

// Produces the following output:
// 6 54


