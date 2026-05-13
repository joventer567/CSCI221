/*

Author: Jonah Scott
Purpose: Final Project
Description: Battling game where you fight squids
Date: 4/23/26

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "squid.hpp"
#include "player.hpp"
#include "squidqueue.hpp"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 2) {
        cout << "Error: Please provide file name(e.g. squid_log.txt)." << endl;
        return 1;
    }
    string user_input;
    Player player;
    int num_items = 0;
    int num_specials = 0;
    bool strength = false;
    bool bounce = false;
    bool weak = false;
    bool guard = false;
    srand(time(0));
    
    cout << endl;
    cout << "You are a student at St Olaf and the campus has been taken over by evil squids." << endl;
    cout << "Your students and faculty have been abducted and you must… oh wait, they're already gone." << endl;
    cout << "Oh well! Might as well get a cookie ice cream cup from the Pause!" << endl;
    cout << endl;

    Squid ugly_squid(10, "ugly_squid");
    Squid stinky_squid(15, "stinky_squid");
    Squid band_squid(20, "band_squid");
    Squid squid_overlord(30, "overlord_squid");
    SquidQueue sq_queue;
    sq_queue.enqueue(ugly_squid);
    sq_queue.enqueue(stinky_squid);
    sq_queue.enqueue(band_squid);
    sq_queue.enqueue(squid_overlord);
    Squid current_squid = sq_queue.dequeue();
    bool squid_power = false;
    bool fire = false;
    int squid_death = 0;
    cout << "As you enter Buntrock Commons through the front door, you feel something slimy ooze into the back of your shoe." << endl;
    cout << "You turn around to see the most hideous squid you've ever seen (and you've seen some pretty hideous squids)." << endl;
    cout << "Only one thing to do: Fight!" << endl;
    
   while (!sq_queue.isEmpty()) {
        
        if (current_squid.dead()) {
            bounce = false;
            guard = false;
            fire = false;
            squid_power = false;
            strength = false;
            weak = false;
            squid_death += 1;
            current_squid = sq_queue.dequeue();

            if (squid_death == 1) {
                cout << "As the hideous squid oozes into the floor beneath you, you breathe in a sigh of relief and loot its remains. " << endl;
                cout << "You find a health pack." << endl;
                player.add_item("health pack");
                cout << "Level up! Your SP has been restored and raised. You've also unlocked fire!" << endl;
                player.raise_sp();
                player.restore_sp();
                player.add_fire();
                cout << endl;
                cout << "But what's this? As you get to the entrance of the game room, you notice a terrible smell." << endl;
                cout << "It's the worst smell you've ever smelled (and you've smelled some pretty gross stuff)." << endl;
                cout << "The smell reveals itself to be another squid, this one dirtier than anything you've ever seen in your life." << endl;
                cout << "Time to take it out!" << endl;
                cout << endl;
            }

            else if (squid_death == 2) {
                cout << "You cough out what seems to be squid feces and vow to take a shower after your cookie ice cream cup." << endl;
                cout << "On the bright side, you find a health pack among the squid remains." << endl;
                player.add_item("health pack");
                cout << "Level up! Your SP has been restored and raised. You've also unlocked bounce!" << endl;
                player.raise_sp();
                player.restore_sp();
                player.add_bounce();
                cout << endl;
                cout << "You continue on your way toward the Pause kitchen, but you hear what seems to be music from a room" << endl;
                cout << "just beyond where the cookie ice cream cup is. You pass it and open the door to find a one-squid band in the center of" << endl;
                cout << "the Pause Mane Stage. She spots you and begins to grin." << endl;
                cout << "You really should have just grabbed the cookie ice cream cup and left..." << endl;
                cout << endl;
            }

            else if (squid_death == 3) {
                cout << "Silence. That's all you hear as you rip the harmonica away from the corpse sitting at your feet." << endl;
                cout << "Maybe that's all you'll ever hear." << endl;
                cout << endl;
                cout << "Oh well, time to get a cookie ice cream cup!" << endl;
                cout << "Level up! Your SP has been restored and raised. You also picked up a harmonica!" << endl;
                player.raise_sp();
                player.restore_sp();
                player.add_item("harmonica");
                cout << endl;
                cout << "It's finally time!! You head to the Pause and ask the squid overlord across the counter for some- aw shucks..." << endl;
            }
        }
        while (!current_squid.dead() && (!player.dead())) {
            cout << endl;
            guard = false;
            cout << "Type 'fight', 'special', 'item', 'guard', 'joke', 'pass', or 'quit'." << endl;
            getline(cin, user_input);
            cout << "------------------------------------------------------------" << endl;
            
            if (user_input == "fight") {
                if (strength == true) {
                    current_squid.strong_punch();
                    strength = false;
                }
                else if (weak == true) {
                    current_squid.weak_punch();
                    weak = false;
                }
                else {
                    current_squid.punch();
                }
                cout << "Kapow! You punch them right where their noggin should be!" << endl;
            }
            else if (user_input == "special") {
                num_specials += 1;
                cout << "What special would you like to use?" << endl;
                string special_choice = "";
                player.show_specials();
                cout << endl;
                getline(cin, special_choice);

                if ((special_choice == "heal") && (player.heal())) {
                    cout << "You heal 5 points. " << endl;
                }

                else if ((special_choice == "strengthen") && (player.strengthen())) {
                    if (weak == true) {
                        cout << "You are no longer weakened." << endl;
                        weak = false;
                    }
                    else {
                        cout << "Your next attack will be significantly stronger." << endl;
                        strength = true;
                    }
                }

                else if ((special_choice == "fire") && (player.fire())) {
                    cout << "You burn the squid! They will take damage every turn." << endl;
                    fire = true;
                }

                else if ((special_choice == "bounce") && (player.bounce())){
                    cout << "Next time the squid swings their tentacle at you, it will bounce right back at them." << endl;
                    bounce = true;
                }

                else {
                    cout << "You can't use " << special_choice << " right now. " << endl;
                    num_specials -= 1;
                }
            }
            else if (user_input == "item") {
                num_items += 1;
                string item_choice = "";
                cout << "What item would you like to use? Here are your available items: " << endl;
                player.sort_inventory();
                player.show_items();
                cout << endl;
                getline(cin, item_choice);

                if ((item_choice == "health pack") && (player.health_pack())) {
                    cout << "You healed five health points." << endl;
                }
                else if ((item_choice == "smash attack") && (player.smash_attack())) {
                    current_squid.smash_attack();
                    cout << "Enemy smash attacked! That packed a punch. " << endl;
                }
                else if ((item_choice == "harmonica") && (player.harmonica())) {
                    cout << "The squid is at first unaffected by your terrible harmonica playing until they notice who's harmonica it is." << endl;
                    cout << "'YOU ROBBED SHARON?\?', the squid cries out in anguish." << endl;
                    cout << "'No', you say. 'I killed her'. " << endl;
                    cout << "The squid is reduced to tears. 'She was my everything! Everything...'" << endl;
                    cout << "All this whining left the squid open for a good knock in the head. You get a good whallop in." << endl;
                    current_squid.strong_punch(); 
                    cout << "Press enter to continue." << endl;
                    string anything;
                    getline(cin, anything);
                    cout << "------------------------------------------------------------" << endl;

                }
                else {
                    cout << "You can't use a " << item_choice << " right now." << endl;
                    num_items -= 1;
                }
            }

            else if (user_input == "joke") {
                int joke_choice = rand() % 10;
                if (joke_choice == 0) {
                    cout << "You tell the most hilarious joke of all time. " << endl;
                    cout << "The squid just laughs and laughs and doesn't even care when you incinerate them with a flamethrower." << endl;
                    current_squid.instakill();
                }
                else {
                    cout << "The squid was not amused." << endl;
                }
            }

            else if (user_input == "guard") {
                cout << "You curl up into the safest position you can think of: a ball. You should take less damage next turn." << endl;
                guard = true;
            }
            else if (user_input == "pass") {
                cout << "You have passed your turn." << endl;
            }
            else if (user_input == "quit") {
                cout << "Thanks for playing!" << endl;  
                return 0;
                }
            
            else {
                cout << user_input << " doesn't seem to work..." << endl;
            }

            if (current_squid.dead() == true) {
                cout << "They're dead!!" << endl;
                break;
            }

            if (player.dead() == true) {
                cout << "You died. GAME OVER" << endl;
                return 0;
            }

            cout << endl;
            cout << "Squid's turn!" << endl;

            if (fire == true) {
                cout << "The squid burns!" << endl;
                current_squid.fire();
            }

            if (current_squid.dead() == true) {
                cout << "They're dead!!" << endl;
                break;
            }

            int squid_action = rand() % 5;
            if (squid_power == true) {
                cout << "The squid hits you with a mega attack!" << endl;
                if (guard == false) {
                    player.hit();
                    player.hit();
                    player.hit();
                }

                else {
                    player.guard_hit();
                    player.guard_hit();
                    player.guard_hit();
                }
                squid_power = false;
                
            }
            else if (squid_action == 0) {
                if (bounce == false) {    
                    cout << "The squid slaps you with their tentacle!" << endl;
                    if (guard == false) {
                        player.hit();
                    }
                    else {
                        player.guard_hit();
                    }
                }    
                else {
                    cout << "The squid slaps you with their tentacle, but it careens off you and into their face!" << endl;
                    current_squid.punch();
                    bounce = false;
                }
            }
            else if (squid_action == 1) {
                cout << "The squid heals!" << endl;
                current_squid.heal();
            }
            else if (squid_action == 2) {
                cout << "The squid charges up..." << endl;
                squid_power = true;

            }

            else if (squid_action == 3) {
                if (current_squid.getName() == "ugly_squid") {
                    cout << "The ugly squid just stands there. That's enough for you to puke." << endl;
                    cout << "You barf out 3sp." << endl;
                    player.lose_sp(3);
                }

                else if (current_squid.getName() == "stinky_squid") {
                    cout << "You take a deep breath in, waiting for the squid to attack." << endl;
                    cout << "Uh oh - that was a mistake. You hack and hack coughs as the smell completely overwhelms you." << endl;
                    if (strength == false) {
                        cout << "Your next attack will be significantly less powerful." << endl;
                        weak = true;
                    }
                    else if (strength == true) {
                        cout << "You are no longer strengthened." << endl;
                        strength = false;
                    }
                }

                else if (current_squid.getName() == "band_squid") {
                    cout << "Wow, her music is so good!! Honestly, why even attack her? You should just sit here and lis-" << endl;
                    cout << "Your thought is cut short as she lets out the deadliest wail. You lose all focus as your knees lock up." << endl;
                    cout << "You lose 5sp and ";
                    player.lose_sp(5);
                    if (strength == false) {
                        cout << "your next attack will be significantly less powerful." << endl;
                        weak = true;
                    }
                    else if (strength == true) {
                        cout << "you are no longer strengthened." << endl;
                        strength = false;
                    }
                
                }
                else if (current_squid.getName() == "overlord_squid") {
                        cout << "The squid overlord says, 'Alright, enough roughhousing! What can I getcha?'" << endl;
                        cout << "Overjoyed, you respond by ordering your cookie ice cream cup." << endl;
                        cout << "'That'll be $3.00.'" << endl;
                        cout << "You... didn't bring your wallet..." << endl;
                        cout << "This squid does not tolerate shoplifting. He punches you square in the face. Twice." << endl;
                        player.hit();
                        player.hit();
                    }
                }

            else {
                cout << "The squid groans as they remember that tomorrow is leg day." << endl;
            }
            cout << endl;
            if (player.return_health() < 0) {
                cout << "player health: 0" << endl;;
            }
            else {
                cout << "player health: " << player.return_health() << endl;
            }
            if (current_squid.return_health() < 0) {
                cout << "squid health: 0" << endl;;
            }
            else {
                cout << "squid health: " << current_squid.return_health() << endl;
            }
            if (player.return_special_points() < 0) {
                cout << "special points left: 0" << endl;
            }
            else {
                cout << "special points left: " << player.return_special_points() << endl;
            }

            if (player.dead() == true) {
                cout << "You died. GAME OVER" << endl;
                return 0;
            }
        }
    }

cout << "The final squid is dead. You kick their limp body away from the ice cream machine and get the most important item of all: " << endl;
cout << "The cookie ice cream cup." << endl;
player.add_item("cookie ice cream cup");
cout << "You eat it and forget all your troubles. What's a few squid murders for a cookie ice cream cup?" << endl;
cout << "THE END" << endl;
ofstream outFile(argv[1]);
if (!outFile.is_open()) {
    cout << "Error opening file." << endl;
    return 1;
}
outFile << "Ending stats: " << endl;
outFile << "You used " << num_items << " items this run." << endl;
outFile << "You used " << num_specials << " specials this run." << endl;
outFile << "You ended with " << player.return_health() << " health and " << player.return_special_points() << " special points." << endl;
outFile << "Thanks for playing!" << endl;
outFile.close();
return 0;

}