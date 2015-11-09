/* 
 * File:   main.cpp
 * Author: Kenton-PC
 *
 * Created on November 7, 2015, 9:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

/*
 * 
 */
//GOTO FUNCTION FOR ACTION
void attacked(int &health, int &item);
void checkBattleInfo(int &health, int &enemyHP, int &status);
//void scripted(int &health); //will use for future project
void getItem(int &item);
void fight_bear(int &health, int &item);
void fight_wolf(int &health, int &item);
void fight_bird(int &health, int &item);
void event(int &health, int &item);



int main(int argc, char** argv) {
  
    srand(static_cast<unsigned int>(time(0)));
    int choice; //CHOICE == R4
    int health = 100; //Health == R5
    int item   = 0;
    int steps = 0;
    
    //Message one - Info about game
    cout << "Welcome to Generic RPG game" << endl;
    cout << "Here you will take on enemies while trying to escape" << endl;
    cout << "You will be able to use items to help you on your journey" << endl;
    
    // this will add and when its over player is winner
    do{    //maybe different maps if remade later one
        cout << "Please select what direction you would like to go" << endl;
        cout << "1 for Left\n2 for Straight\n3 for Right\n" << endl;
        cin  >> choice;

        //Even choice function to get out
        //Will be CMP function in GOTO
        if(choice == 1){
            event(health, item);
        }
        else if(choice == 2){
            event(health, item);
        }
        else if(choice == 3){
            event(health, item);
        }
        if(health == 0){
            cout << "Game Over" << endl;
            steps = 99;
        }
    }while(steps<10);
        
    cout << "You made it out alive" << endl;
    
    return 0;
}

void attacked(int &health, int &item){
    //Choose from 3 animals (will be 3 functions)
    int chooseEvent = rand()%3+1;
    
    //selecto the animal
    if(chooseEvent == 1){
        fight_wolf(health,item);
    }
    if(chooseEvent == 2){
        fight_bird(health,item);
    }
    if(chooseEvent == 3){
        fight_bear(health,item);
    }
    
}

void checkBattleInfo(int &health, int &enemyHP, int &status){
    /*STAT INFO
    0 = Player alive
    1 = Player dead
    2 = Animal dead
    */
    
    
    if(health <= 0){
        cout << "You have died\n GAME OVER" << endl;
        health = 0; //set it equal to 0 so it wont show a negative value at G.O screen
        status = 1;  //1 = player dead
    }
    else if(enemyHP <=0){
        cout << "You killed the animal" << endl;
        enemyHP = 0;
        status = 2;  //animal is dead
    }
    
}

//setup for bear fight
void fight_bear(int &health, int &item){
    int choice; //get user input for attack options
    int status = 0;  //Register for staus (dead/alive)
    //WILL need 3 registers for animal attacks. USE R8-10
    int enemyHP = 80;    //HP R8
    int enemyAtk = 40;   //For Attack power R10
    
    //Messagee 3
    cout << "You ran into a bear" << endl;
    
    //This is what loops for fight
    _Battle:
    checkBattleInfo(health,enemyHP,status); //Use to see if loss or win before going another round
    
    if(status == 0){  //if player & animal is alive fight another round
        cout << "\nWhat do you want to do? \nFight(1)  Defend(2)" << endl;
        cout <<  "UseItem(3)  Run(4)" << endl;
        cin >> choice;    
    } 
    
    
    //Going to lead to other functions
    if(choice == 1){
       //Message 4
        cout << "You chose to attack" << endl;
        enemyHP -= 35;   //You attck (not using variable since I will run out of registers)
        cout << "The bears HP was weakened:" << enemyHP << endl;
        checkBattleInfo(health,enemyHP,status);
        
        //this is if the bear survives the attack
        if(status == 0){
            cout << "The bear swings at you" << endl;
            health -= enemyAtk;
            cout << "You were hit:" << health << "/100" << endl;   //Will try to include speed to avoid hits
        
            goto _Battle; //Loop back to Battle function
        }
    } //end of attack if loop
    
    else if(choice == 2){ //to defend
        //MESSAGE
        cout << "You choose to defend" << endl;
        
        if(status == 0){ //check status to see if player was alive and loop back to options
            //Message with check info
            cout << "The bear swings at you" << endl;
            health -= (enemyAtk/4);  //does 1/4 damage
            checkBattleInfo(health,enemyHP,status);  //checks to see status
            cout << "You were hit:" << health << "/100" << endl;
        
            goto _Battle;
        }
        
    }
    else if(choice == 3){
        if(item > 0){
            cout << "You used a potion" << endl;
            cout << "Health:" << health << endl;
            item--;
            
            goto _Battle;
        }
        else{
            cout << "You dont have any potions" << endl;
            
            goto _Battle;
        }
              
    }
    
    else if(choice == 4){
        cout << "You try running away" << endl;
        if(health > enemyHP){
            cout << "You got away" << endl;
        }
        else{
            cout << "You couldnt run away" << endl;
            goto _Battle;
        }
    }
}

void fight_wolf(int &health, int &item){
        int choice; //get user input for attack options
    int status = 0;  //Register for staus (dead/alive)
    //WILL need 3 registers for animal attacks. USE R8-10
    int enemyHP = 40;    //HP R8
    int enemyAtk = 15;   //For Attack power R10
    
    //Messagee 3
    cout << "You ran into a wolf" << endl;
    
    //This is what loops for fight
    _Battle:
    checkBattleInfo(health,enemyHP,status); //Use to see if loss or win before going another round
    
    if(status == 0){  //if player & animal is alive fight another round
        cout << "\nWhat do you want to do? \nFight(1)  Defend(2)" << endl;
        cout <<  "UseItem(3)  Run(4)" << endl;
        cin >> choice;    
    } 
    
    
    //Going to lead to other functions
    if(choice == 1){
       //Message 4
        cout << "You chose to attack" << endl;
        enemyHP -= 35;   //You attck (not using variable since I will run out of registers)
        cout << "The wolfs HP was weakened:" << enemyHP << endl;
        checkBattleInfo(health,enemyHP,status);
        
        //this is if the bear survives the attack
        if(status == 0){
            cout << "The wolf runs at you" << endl;
            health -= enemyAtk;
            cout << "You were hit:" << health << "/100" << endl;   //Will try to include speed to avoid hits
        
            goto _Battle; //Loop back to Battle function
        }
    } //end of attack if loop
    
    else if(choice == 2){ //to defend
        //MESSAGE
        cout << "You choose to defend" << endl;
        
        if(status == 0){ //check status to see if player was alive and loop back to options
            //Message with check info
            cout << "The wolfs runs at you" << endl;
            health -= (enemyAtk/4);  //does 1/4 damage
            checkBattleInfo(health,enemyHP,status);  //checks to see status
            cout << "You were hit:" << health << "/100" << endl;
        
            goto _Battle;
        }
        
    }
    else if(choice == 3){

    }
    
    else if(choice == 4){
        cout << "You try running away" << endl;
        if(health > enemyHP){
            cout << "You got away" << endl;
        }
        else{
            cout << "You couldnt run away" << endl;
            goto _Battle;
        }
    }
}
void fight_bird(int &health, int &item){
    int choice; //get user input for attack options
    int status = 0;  //Register for staus (dead/alive)
    //WILL need 3 registers for animal attacks. USE R8-10
    int enemyHP = 45;    //HP R8
    int enemyAtk = 30;   //For Attack power R10
    
    //Messagee 3
    cout << "You ran into a hawk" << endl;
    
    //This is what loops for fight
    _Battle:
    checkBattleInfo(health,enemyHP,status); //Use to see if loss or win before going another round
    
    if(status == 0){  //if player & animal is alive fight another round
        cout << "\nWhat do you want to do? \nFight(1)  Defend(2)" << endl;
        cout <<  "UseItem(3)  Run(4)" << endl;
        cin >> choice;    
    } 
    
    
    //Going to lead to other functions
    if(choice == 1){
       //Message 4
        cout << "You chose to attack" << endl;
        enemyHP -= 35;   //You attck (not using variable since I will run out of registers)
        cout << "The hawks HP was weakened:" << enemyHP << endl;
        checkBattleInfo(health,enemyHP,status);
        
        //this is if the bear survives the attack
        if(status == 0){
            cout << "The hawk soars towards you" << endl;
            health -= enemyAtk;
            cout << "You were hit:" << health << "/100" << endl;   //Will try to include speed to avoid hits
        
            goto _Battle; //Loop back to Battle function
        }
    } //end of attack if loop
    
    else if(choice == 2){ //to defend
        //MESSAGE
        cout << "You choose to defend" << endl;
        
        if(status == 0){ //check status to see if player was alive and loop back to options
            //Message with check info
            cout << "The hawk soars towards you" << endl;
            health -= (enemyAtk/4);  //does 1/4 damage
            checkBattleInfo(health,enemyHP,status);  //checks to see status
            cout << "You were hit:" << health << "/100" << endl;
        
            goto _Battle;
        }
        
    }
    else if(choice == 3){

    }
    
    else if(choice == 4){
        cout << "You try running away" << endl;
        if(health > enemyHP){
            cout << "You got away" << endl;
        }
        else{
            cout << "You couldnt run away" << endl;
            goto _Battle;
        }
    }
}
//void scripted()

void getItem(int &item){
    cout << "You found a potion\n This refills 20HP" << endl;
    item += 1;
}

void event(int &health, int &item){
    //will choose what event will happen
    int chooseEvent = rand()%2+1;    //CHOOSEEVENT = R5
    
    //CMP to select event and then GOTO function call
    if(chooseEvent==1){
        //Attacked
        attacked(health, item);
    }
    /*if(chooseEvent==2){
        //Scripted Event
        scripted();
    }
     */
    
    if(chooseEvent==2){
        //Get item
        getItem(item);
    }
    
}