import random

# Define the company names
companies = ['Apple', 'Microsoft', 'Google', 'Amazon', 'Tesla']

# Generate artificial stock prices for the specified number of years
def generate_stock_prices(years):
    stock_prices = {}
    current_year = 2023

    for company in companies:
        stock_prices[company] = []
        starting_price = random.uniform(50, 500)
        growth_factor = random.uniform(0.9, 1.1)
        price = starting_price

        for _ in range(years):
            stock_prices[company].append(price)
            price *= growth_factor
            growth_factor = random.uniform(0.9, 1.1)

    return stock_prices

# Define the expert system
def predict_action(company, investment, years):
    stock_prices = generate_stock_prices(years)
    prices = stock_prices[company]

    # Generate a predicted price
    predicted_price = prices[-1] * random.uniform(0.95, 1.05)

    if predicted_price > prices[-1]:
        return "Buy"
    elif predicted_price < prices[-1]:
        return "Sell"
    else:
        return "Hold"

# Start the chatbot
print("Welcome to the Stock Market Prediction Chatbot!")

while True:
    company = input("Enter a company name (Apple, Microsoft, Google, Amazon, Tesla) or 'quit' to exit: ")

    if company.lower() == 'quit':
        break

    if company in companies:
        years = int(input("Enter the number of years: "))
        investment = float(input("Enter the amount to invest: $"))

        action = predict_action(company, investment, years)
        print(f"For {company}:")
        print(f"Predicted Action: {action}")
        print()
    else:
        print("Invalid company name. Please try again.")
        print()
