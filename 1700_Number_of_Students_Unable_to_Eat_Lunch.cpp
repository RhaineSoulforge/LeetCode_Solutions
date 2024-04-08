/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  countStudents
// Last Modified:  April 8th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Returns the number of students that haven't eaten.
//
// In:  student - The queue of students and their preffered sandwich type.
//      sandwiches - The stack of sandwiches currently available to the student in queue.
// Out:  uneaten - The number of students that did not eat.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int countStudents(vector<int>& students, vector<int>& sandwiches)
{
   int numStudents = (int)students.size();  //Number of Students
   int uneaten = numStudents;  //Number of Student have not eaten
   bool changed = true;  //Did someone eat?

   //If someone has eaten keep moving the queue.
   while(changed)
   {
      changed = false;
      for(int i=0; i<numStudents; i++)
      {
         //Stop if there are no more students in queue or sandwiches on the stack.
         if(students.empty() || sandwiches.empty())
            break;

         //The students like this type of sandwich.
         if(students[0] == sandwiches[0])
         {
            uneaten--;  //Decrease number of hungry students
            sandwiches.erase(sandwiches.begin());  //Remove sandwich
            students.erase(students.begin());  //Remove student
            numStudents = (int)students.size();  //Update number of student in queue
            changed = true;  //Someone ate!
         }
         else
         {
            //Move student to back of queue
            students.push_back(students[0]);
            students.erase(students.begin());
         }
      }

      //If queue is empty or there are no more sandwich then leave
      if(students.empty() || sandwiches.empty())
         break;
   }

   return uneaten;
}