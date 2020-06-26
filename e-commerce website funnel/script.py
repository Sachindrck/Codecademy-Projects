import codecademylib
import pandas as pd

visits = pd.read_csv('visits.csv',
                     parse_dates=[1])
cart = pd.read_csv('cart.csv',
                   parse_dates=[1])
checkout = pd.read_csv('checkout.csv',
                       parse_dates=[1])
purchase = pd.read_csv('purchase.csv',
                       parse_dates=[1])

#print(visits.head())
#print(cart.head())
#print(checkout.head())
#print(purchase.head())


visit_cart = pd.merge(visits, cart, how='left')
#print(visit_cart)
#print(len(visit_cart))

cart_visitors = visit_cart[visit_cart.cart_time.isnull()]
#print(cart_visitors)
#print(len(cart_visitors))


print("1. Visitors but not added any item into cart: {}%".format(round(100.0 * len(cart_visitors) / len(visit_cart), 2)))


cart_checkout = pd.merge(cart, checkout, how='left')
#print(cart_checkout)
#print(len(cart_checkout))

not_purchased = len(cart_checkout[cart_checkout.checkout_time.isnull()])
#print(not_purchased)

print("2. Added item to cart but doesn't checkout: {}%".format(round(100.0 * not_purchased / len(cart_checkout), 3)))


all_data = visits.merge(cart, how='left').merge(checkout, how='left').merge(purchase, how='left')
#print(all_data.head(10))

checkout_num = len(all_data[~all_data.checkout_time.isnull()])
purchased_num = len(all_data[(~all_data.checkout_time.isnull()) & (all_data.purchase_time.isnull())])

print("3. checkout but doesn't purchased : {}%".format(round(100.0 * purchased_num / checkout_num, 2)))


# Average time to purchase

all_data['time_to_purchase'] = all_data.purchase_time - all_data.visit_time

print(all_data.time_to_purchase)
print(all_data.time_to_purchase.mean())