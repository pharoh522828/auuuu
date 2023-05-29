import random

# Define possible user responses
GREETING_KEYWORDS = ("hello", "hi", "greetings", "hey", "hola")
GREETING_RESPONSES = ["Hello! Welcome to our restaurant.", "Hi there! How can I assist you?", "Greetings! What can I do for you?"]

MENU_KEYWORDS = ("menu", "food", "dishes")
MENU_RESPONSES = ["Sure! Here is our menu:", "Here are the dishes we offer:", "Take a look at our menu options:"]

ORDER_KEYWORDS = ("order", "place an order", "food")
ORDER_RESPONSES = ["Sure, I can help you with that. What would you like to order?", "What dish would you like to order?", "Please let me know your order."]

GOODBYE_KEYWORDS = ("bye", "goodbye", "see you", "later")
GOODBYE_RESPONSES = ["Goodbye! Have a great day!", "Farewell! Come back soon!", "See you later!"]

THANK_KEYWORDS = ("thank", "thanks", "appreciate")
THANK_RESPONSES = ["You're welcome!", "No problem!", "Glad I could help!"]

UNKNOWN_RESPONSES = ["I'm sorry, I didn't understand. Could you please rephrase that?", "I'm still learning. Can you provide more details?", "Apologies, but I'm not sure what you mean."]

# Define available menu items and their prices
MENU_ITEMS = {
    "pizza": {"price": 10.99, "description": "Delicious pizza with various toppings."},
    "pasta": {"price": 8.99, "description": "Freshly made pasta with a choice of sauces."},
    "burger": {"price": 9.99, "description": "Juicy burger with fries and a side of your choice."},
    "salad": {"price": 7.99, "description": "Healthy salad with fresh greens and dressings."},
}

# Define cart for storing the customer's order
cart = {}

# Define chatbot function
def chatbot():
    while True:
        user_input = input("Customer: ").lower()

        if any(keyword in user_input for keyword in GREETING_KEYWORDS):
            response = random.choice(GREETING_RESPONSES)
        elif any(keyword in user_input for keyword in MENU_KEYWORDS):
            menu = "\n".join([f"{item.capitalize()}: ${details['price']:.2f} - {details['description']}" for item, details in MENU_ITEMS.items()])
            response = random.choice(MENU_RESPONSES) + "\n" + menu
        elif any(keyword in user_input for keyword in ORDER_KEYWORDS):
            order_item = None
            for item in MENU_ITEMS:
                if item in user_input:
                    order_item = item
                    break
            if order_item:
                if order_item in cart:
                    cart[order_item] += 1
                else:
                    cart[order_item] = 1
                response = f"{order_item.capitalize()} added to your order."
            else:
                response = "I'm sorry, we don't have that item on our menu."
        elif any(keyword in user_input for keyword in GOODBYE_KEYWORDS):
            response = random.choice(GOODBYE_RESPONSES)
            break
        elif any(keyword in user_input for keyword in THANK_KEYWORDS):
            response = random.choice(THANK_RESPONSES)
        else:
            response = random.choice(UNKNOWN_RESPONSES)

        print("Chatbot:", response)

# Run the chatbot
print("Chatbot: Hello! Welcome to our restaurant. How can I assist you?")
chatbot()

# Display the final order and total
if cart:
    print("\n--- Your Order ---")
    total = 0
    for item, quantity in cart.items():
        price = MENU_ITEMS[item]["price"] * quantity
        print(f"{item.capitalize()} x {quantity}: ${price:.2f}")
        total += price
    print("------------------")
    print(f"Total: ${total:.2f}")