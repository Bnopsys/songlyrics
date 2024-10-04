#include <iostream>
#include <string>
#include <cstring>
#include <tuple>

/*
Command to run code:
clang++ -std=c++11 99bottlesofbeer.cpp && ./a.out
*/

std::string tens_place(int tens);
std::string ones_place(int ones);
std::string teens_place(int teens);
std::tuple <int, int> separate_tens_and_ones(int current_beer);
int handle_exceptions(int tens, int ones);
void song_lyrics(std::string current_number, std::string next_output);
std::string convert_int_to_string(int number);

int main(){
    int max_beers = 99;
    
    for (int remaining_beers = max_beers; remaining_beers > 0; remaining_beers--){
        int next_beer = remaining_beers - 1;
        std::string current_output = convert_int_to_string(remaining_beers);
        std::string next_output = convert_int_to_string(next_beer);
        std::cout << "Current Beer: " << current_output << std::endl << "Next Beer: " << next_output << std::endl;
        song_lyrics(current_output, next_output);
    }
    return 0;
}

std::string convert_int_to_string(int number){
    int current_tens;
    int current_ones;
    std::string current_output = "";
    std::tie(current_tens, current_ones) = separate_tens_and_ones(number);
    int handler_value = handle_exceptions(current_tens, current_ones);

    switch (handler_value){
        case 0:
            current_output.append(tens_place(current_tens));
            current_output.append("-");
            current_output.append(ones_place(current_ones));
            break;
        case 1: // multiple of ten
            current_output.append(tens_place(current_tens));
            break;
        case 2: // teen value
            current_output.append(teens_place(current_ones));
            break;
        case 3: // single digit value
            current_output.append(ones_place(current_ones));
            break;
        default:
            current_output.append("ERROR");
        }
        return current_output;
}
std::tuple <int, int> separate_tens_and_ones(int current_beer){
    int beer_tens = current_beer / 10;
    int beer_ones = current_beer % 10;
    return std::tuple<int, int> (beer_tens, beer_ones);
}

std::string tens_place(int tens){
    std::string current_tens_place;

    switch (tens){
        case 0:
            current_tens_place = "Zero";
            break;
        case 1:
            current_tens_place = "Ten";
            break;
        case 2:
            current_tens_place = "Twenty";
            break;
        case 3:
            current_tens_place = "Thirty";
            break;
        case 4:
            current_tens_place = "Forty";
            break;
        case 5:
            current_tens_place = "Fifty";
            break;
        case 6:
            current_tens_place = "Sixty";
            break;
        case 7:
            current_tens_place = "Seventy";
            break;
        case 8:
            current_tens_place = "Eighty";
            break;
        case 9:
            current_tens_place = "Ninety";
            break;
        default:
            return 0;

    }
    return current_tens_place;
}

std::string ones_place(int ones){
    std::string current_ones_place;

    switch (ones){
        case 1:
            current_ones_place = "One";
            break;
        case 2:
            current_ones_place = "Two";
            break;
        case 3:
            current_ones_place = "Three";
            break;
        case 4:
            current_ones_place = "Four";
            break;
        case 5:
            current_ones_place = "Five";
            break;
        case 6:
            current_ones_place = "Six";
            break;
        case 7:
            current_ones_place = "Seven";
            break;
        case 8:
            current_ones_place = "Eight";
            break;
        case 9:
            current_ones_place = "Nine";
            break;
        default:
            return 0;
    }
    return current_ones_place;
}

std::string teens_place(int teens){
    std::string current_teens_place;

    switch (teens){
        case 0:
            current_teens_place = "Ten";
            break;
        case 1:
            current_teens_place = "Eleven";
            break;
        case 2:
            current_teens_place = "Twelve";
            break;
        case 3:
            current_teens_place = "Thirteen";
            break;
        case 4:
            current_teens_place = "Fourteen";
            break;
        case 5:
            current_teens_place = "Fifteen";
            break;
        case 6:
            current_teens_place = "Sixteen";
            break;
        case 7:
            current_teens_place = "Seventeen";
            break;
        case 8:
            current_teens_place = "Eighteen";
            break;
        case 9:
            current_teens_place = "Nineteen";
            break;
        default:
            return 0;
    }
    return current_teens_place;
}

int handle_exceptions(int tens, int ones){
    int return_tens_val = 1;
    int return_teens_val = 2;
    int return_single_digit_val = 3;
    // check modulus for multiples of ten
    if (ones == 0){
        return return_tens_val;
    }

    // check divide no for 1
    else if (tens == 1){
        return return_teens_val;
    }

    // check divide no for 0
    else if (tens == 0){
        return return_single_digit_val;
    }
    else {
        return 0;
    }
}

void song_lyrics(std::string current_number, std::string next_output){
    std::string additional_s = "s";
    std::string nxt_additional_s = "s";
    std::string punctuation = ",";
    if (current_number == "One"){
        additional_s = "";
    }
    else if (next_output == "One"){
        nxt_additional_s = "";
    }

    if (next_output == "Zero"){
        punctuation = ".";
    }
    std::string line1 = current_number + " bottle" +  additional_s + " of beer on the wall, \n";
    std::string line2 = current_number + " bottle" + additional_s + " of beer, \n";
    std::string line3 = "Take one down, pass it around,\n";
    std::string line4 = next_output + " bottle" + nxt_additional_s + " of beer" + punctuation + "\n";

    
    std::cout << line1 << line2 << line3 << line4;
}