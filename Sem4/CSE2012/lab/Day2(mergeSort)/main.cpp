#include "headers/app.h"

int main(){
    char testMode;

cout<<R"(
__/\\\\____________/\\\\______________________________________________________________/\\\\\\\\\\\_____________________________________________________
__\/\\\\\\________/\\\\\\____________________________________________________________/\\\/////////\\\__________________________________________________
___\/\\\//\\\____/\\\//\\\________________________________/\\\\\\\\__________________\//\\\______\///__________________________________/\\\____________
____\/\\\\///\\\/\\\/_\/\\\_____/\\\\\\\\___/\\/\\\\\\\___/\\\////\\\_____/\\\\\\\\____\////\\\_____________/\\\\\_____/\\/\\\\\\\___/\\\\\\\\\\\______
_____\/\\\__\///\\\/___\/\\\___/\\\/////\\\_\/\\\/////\\\_\//\\\\\\\\\___/\\\/////\\\______\////\\\________/\\\///\\\__\/\\\/////\\\_\////\\\////______
______\/\\\____\///_____\/\\\__/\\\\\\\\\\\__\/\\\___\///___\///////\\\__/\\\\\\\\\\\__________\////\\\____/\\\__\//\\\_\/\\\___\///_____\/\\\_________
_______\/\\\_____________\/\\\_\//\\///////___\/\\\__________/\\_____\\\_\//\\///////____/\\\______\//\\\__\//\\\__/\\\__\/\\\____________\/\\\_/\\____
________\/\\\_____________\/\\\__\//\\\\\\\\\\_\/\\\_________\//\\\\\\\\___\//\\\\\\\\\\_\///\\\\\\\\\\\/____\///\\\\\/___\/\\\____________\//\\\\\____
_________\///______________\///____\//////////__\///___________\////////_____\//////////____\///////////________\/////_____\///______________\/////____
)";

    cout<<endl;
    cout<<"[?]Enter Mode (`T` => TEST MODE | `any char` for NORMAL MODE): ";
    cin>>testMode;
    app(testMode);
    return 0;
}