
#ifndef Chapters_H
#define Chapters_H

string firstChapter()
{
      string name;
      int answer;
      cout << "What your name will be?: ";
      cin >> name;
      cout << "-----------------------" << endl;
      cout << "---------------" << endl;
      cout << "----------" << endl;
      cout << "Once upon a time, in the south of the Mistlands, in the heat of the war between light and darkness, the two lovers had vowed to meet on a lonely night." << endl;
      cout << "--------------" << endl;
      cout << "You suddenly wake up to the sound of a scream and you start running straight to where the sound came from. " << endl;
      cout << "At the end of the road you see a huge stone door surrounded by branches and moss. and suddenly you hear a sound." << endl;
      cout << "The Voice: Welcome  " << name << ",looking for your friend?" << endl;
      cout << endl;
      do
      {
            cout << "1.  Wait a minute, who are you ? How do you know my name? " << endl;
            cout << "2.  Where is my beloved ? Tell me NOW !!!! " << endl;
            cout << "3.  *Explore the dungeon !!*(if you choose this, you will start playing.)" << endl;
            cout << "Answer: ";
            cin >> answer;
            cout << endl;
            if (answer == 1)
            {
                  cout << "The Voice: It really doesn't matter who i am. I am just here to help you" << endl;
            }
            else if (answer == 2)
            {
                  cout << "The Voice :  Thats a good question my friend but i think the answer is deep down in the dungeon" << endl;
            }
            else if (answer == 3)
            {
                  system("cls");
                  return name;
            }     
      } while (answer != 1 || answer != 2 || answer != 3);
      return "unknown";
}
string chooseCharacter()
{
      system("cls");
      int input;
      cout << "The voice: Wait before you go i need to bless my powers to you down there is too dangerous." << endl;
      cout << "The voice: You have 3 options: Warrior,Mage and Rogue each have their unique powers choose wisely." << endl;
      cout << "Press 1 to choose warrior" << endl;
      cout << "Press 2 to choose mage" << endl;
      cout << "Press 3 to choose rogue" << endl;
      do
      {
            cin >> input;
            if (input == 1)
            {
                  return "warrior";
            }
            else if (input == 2)
            {
                  return "mage";
            }
            else if (input == 3)
            {
                  return "rouge";
            }
            else
            {
                  cout << "enter a valid input" << endl;
            }
      } while (1);
}
void boss_story()
{
      cout << "-After all the war and hardship, you see a dark room with a huge entrance." << endl;
      cout << "........";
      cout << "....";
      cout << "-You also enter this desolate dark room hoping to find the one you love AND suddenly the torches start burning in order......." << endl;
      cout << "-With the last torch burning, you see your loved one exhausted and next to it you see a monster as gigantic as it is terrifying!!!!" << endl;
      cout << "And you hear a voice. You've come at last." << endl;
      cout << "The voice: You've come at last.";
      cout << "Unfortunately your coming this far means nothing, You will be ruined at last " << endl;
      cout << "-You recognize this sound and immediately draw your weapon!!" << endl;
      cout << "                                  FIGHT BEGINS!!!!                                " << endl;
}



#endif