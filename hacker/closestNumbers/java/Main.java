import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class ClosestProblem
{
	public void solve(ArrayList<Integer> arrayList, int sizeOfList)
	{
		Collections.sort(arrayList);
	}
}

public class Main
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		int sizeOfList = scanner.nextInt();
		ArrayList<Integer> arrayList = new ArrayList<Integer>();
		scanner = new Scanner(System.in).useDelimiter(" |\\n");
		while(scanner.hasNext())
		{
			arrayList.add(new Integer(scanner.nextInt()));
		}
		
		ClosestProblem closestProblem = new ClosestProblem();
		closestProblem.solve(arrayList, sizeOfList);
	}
}
