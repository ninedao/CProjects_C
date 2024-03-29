cmake_minimum_required(VERSION 3.14)
project(CProjects_C C)

set(CMAKE_C_STANDARD 99)

add_executable(CProjects_C main.c)
add_executable(cLinkList  src/List/CircleLinkList/cLinkList.c)
add_executable(dulLinkList src/List/DoubleLinkList/dulLinkList.h  src/List/DoubleLinkList/dulLinkList.c)
add_executable(LinkListWithNode  src/List/LinkListWithNode/LinkList.c)
add_executable(PolynomialList  src/List/PolynomialList/PolynomialList.c)
add_executable(SequenceStack  src/Stack/SequenceStack/SequenceStack.c)
add_executable(LinkStack  src/Stack/LinkStack/LinkStack.c)
add_executable(MatchBrace  src/Stack/LinkStack/MatchBrace/MatchBrace.c)
add_executable(LineEdit  src/Stack/SequenceStack/LineEdit/LineEdit.c)
add_executable(Maze  src/Stack/SequenceStack/Maze/Maze.c)
add_executable(EvaluateExpression  src/Stack/SequenceStack/EvaluateExpression/EvaluateExpression.c)
add_executable(Hanoi src/Stack/SequenceStack/Hanoi/Hanoi.c)
add_executable(LinkQueue src/Queue/LinkQueue/LinkQueue.c)
add_executable(SqQueue src/Queue/SqQueue/SqQueue.c)
add_executable(Bank_Simulattion src/Queue/Bank_Simulation/Bank_Simulattion.c)
add_executable(SString src/String/SString/SString.c)
add_executable(HString src/String/HString/HString.c)
add_executable(LString src/String/LString/LString.c)
add_executable(WordIndexTable src/String/Index/WordIndexTable.c)
add_executable(SequenceArray src/Array/SequenceArray.c)
add_executable(SparseMatrix src/Matrix/SparseMatrix.c)
add_executable(CrossList src/Matrix/CrossList/CrossList.c)