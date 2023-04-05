#pragma once

namespace Messages {
	const char GREATER_THAN= '>';
	const char ITEM_ADDED[] = " The item has been added successfully. ";
	const char ALREADY_EXISTS[] = " The item already exists. ";
	const char DOES_NOT_EXISTS[] = "This item does not exist. ";
	const char ITEM_REMOVED[] = " The item has been removed successfully. ";
	const char NUMBER_OF_ITEMS_IS[] = " The number of items is ";
	const char THE_CART_IS_EMPTY[] = " The cart is empty ";
	const char THE_CART_IS_NOT_EMPTY[] = " The cart is not empty ";
	const char THE_PRICE_OF[] = " The price of ";
	const char IS[] = " is ";
	const char TOTAL_PRICE_IS[] = " Total price of items in the cart is ";
	const char SORTED_CART[] =" The cart has been sorted successfully ";
	const char SAVED_CART[] = "The cart has been save successfully in " ;
	const char ERROR[]= "Error!";
}
namespace Command {
	const char ADD_ITEM[] = "addItem";
	const char REMOVE_ITEM[] = "removeItem";
	const char GET_ITEMS_COUNT[] = "getItemsCount";
	const char IS_EMPTY[] = "isEmpty";
	const char GET_PRICE_OF[] = "getPriceOf";
	const char GET_TOTAL_PRICE[] = "getTotalPrice";
	const char SORT_BY_NAME[] = "sortByName";
	const char SAVE[] = "save";
}