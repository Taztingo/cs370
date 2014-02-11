import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class ClosestProblem
{
	private ArrayList<Integer> answer = new ArrayList<Integer>();

	public void solve(ArrayList<Integer> arrayList, int size)
	{
		Collections.sort(arrayList);
		final int UNSET = -1;
		long minDistance = UNSET;
		long distance;

		Collections.sort(arrayList);
		for(int i = 0; i < size - 1; i++)
		{
			int element1 = arrayList.get(i);
			int element2 = arrayList.get(i + 1);

			distance = Math.abs(element1 - element2);

			if(distance < minDistance || minDistance == UNSET)
			{
				answer.clear();
				minDistance = distance;
				answer.add(element1);
				answer.add(element2);
			}
			else if(distance == minDistance)
			{
				answer.add(element1);
				answer.add(element2);
			}
		}
	}

	public String toString()
	{
		String allPairs = "";

		for(int i = 0; i < answer.size(); i++)
		{
			allPairs += answer.get(i) + " ";
		}

		if(allPairs.length() > 0)
		{
			allPairs = allPairs.substring(0, allPairs.length() - 1);
		}

		return allPairs;
	}
}

public class Main2
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		int sizeOfList = scanner.nextInt();
		ArrayList<Integer> arrayList = new ArrayList<Integer>();
		while(scanner.hasNextInt())
		{
			arrayList.add(new Integer(scanner.nextInt()));
		}
		ClosestProblem closestProblem = new ClosestProblem();
		closestProblem.solve(arrayList, sizeOfList);
		System.out.println(closestProblem.toString());
	}
}
