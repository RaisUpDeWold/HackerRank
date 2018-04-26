class Student extends Person{
	private int[] testScores;

    /*	
    *   Class Constructor
    *   
    *   @param firstName - A string denoting the Person's first name.
    *   @param lastName - A string denoting the Person's last name.
    *   @param id - An integer denoting the Person's ID number.
    *   @param scores - An array of integers denoting the Person's test scores.
    */
    // Write your constructor here

    /*	
    *   Method Name: calculate
    *   @return A character denoting the grade.
    */
    // Write your method here
    Student(String firstName, String lastName, int id, int[] testScores) {
		super(firstName, lastName, id);

		this.testScores = testScores;
	}

	public char calculate() {
		int totalScore = 0;
		for (int testScore : testScores) {
			totalScore += testScore;
		}

		if (totalScore >= testScores.length * 90) {
			return 'O';
		} else if (totalScore >= testScores.length * 80) {
			return 'E';
		} else if (totalScore >= testScores.length * 70) {
			return 'A';
		} else if (totalScore >= testScores.length * 55) {
			return 'P';
		} else if (totalScore >= testScores.length * 40) {
			return 'D';
		} else {
			return 'T';
		}
	}
}
