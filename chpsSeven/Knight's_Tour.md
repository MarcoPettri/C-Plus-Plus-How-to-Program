7. 22 ***(Introducing Heuristic Programming with the Knight's Tour)*** An interesting puzzler for chess buffs is the Knight's Tour problem, originally proposed by the mathematician Euler. Can the knight piece move around an empty chessboard and touch each of the 64 squares once and only once? We study this intriguing problem in depth here. The knight makes only L-shaped moves (two spaces in one direction and one space in a perpendicular direction). Thus, as shown in the figure below, from a square near the middle of an empty chessboard, the knight (labelled K) can make eight different moves (numbered 0 through 7).

|   |  0 | 1  |  2 |  3 | 4  | 5  | 6  | 7  |
|---|---|---|---|---|---|---|---|---|
| 0  |   |   |   |   |   |   |   |   |
| 1 |   |   |   | 2  |   |  1 |   |   |
| 2  |   |   | 3  |   |   |   | 0  |   |
| 3  |   |   |   |   | K  |   |   |   |
| 4  |   |   |  4 |   |   |   |  7 |   |
| 5  |   |   |   |  5 |   |  6 |   |   |
| 6  |   |   |   |   |   |   |   |   |
| 7  |   |   |   |   |   |   |   |   |

- a) Write a program to move the knight around the chessboard. Keep a counter that varies from 1 to 64. 
     Record the latest count in each square the knight moves to. 
	 Test each potential move to see if the knight has already visited that square. 
	 Test every potential move to ensure that the knight does not land off the chessboard. Run the application. 
	 How many moves did the knight make?


- B) After attempting to write and run a Knight's Tour program, you've probably developed some valuable insights. 
    We'll use these insights to develop a heuristic (i.e., a common-sense rule) for moving the knight. 
	Heuristics do not guarantee success, but a carefully developed heuristic greatly improves the chance of success. 
	You may have observed that the outer squares are more troublesome than the squares nearer the center of the board. 
	In fact, the most troublesome or inaccessible squares are the four corners.
	<br> &nbsp; Intuition may suggest that you should attempt to move the knight to the most troublesome squares first and leave open those 
	that are easiest to get to so that when the board gets congested near the end of the tour, there will be a greater chance of success.
	<br> &nbsp; We could develop an “accessibility heuristic” by classifying each of the squares according to how accessible it is and 
	always moving the knight (using the knight's L-shaped moves) to the most inaccessible square. We fill two- dimensional array accessibility 
	with numbers indicating from how many squares each particular square is accessible. On a blank chessboard, each of the 16 squares nearest the center is rated as 8, 
	each corner square is rated as 2, and the other squares have accessibility numbers of 3, 4 or 6 as follows:
```c++
					2 3 4 4 4 4 3 2
					3 4 6 6 6 6 4 3
					4 6 8 8 8 8 6 4
					4 6 8 8 8 8 6 4
					4 6 8 8 8 8 6 4
					4 6 8 8 8 8 6 4
					3 4 6 6 6 6 4 3
					2 3 4 4 4 4 3 2
```
- Write a new version of the Knight's Tour, using the accessibility heuristic. The knight should always move to the square with the lowest accessibility number. 
    In case of a tie, the knight may move to any of the tied squares. Therefore, the tour may begin in any of the four corners. 
	[Note: As the knight moves around the chessboard, your application should reduce the accessibility numbers as more squares become occupied.
	In this way, at any given time during the tour, each available square's accessibility number will remain equal to precisely the number of squares from which that square may be reached.] 
	Run this version of your program. Did you get a full tour? Modify the program to run 64 tours, one starting from each square of the chessboard. 
	How many full tours did you get? 