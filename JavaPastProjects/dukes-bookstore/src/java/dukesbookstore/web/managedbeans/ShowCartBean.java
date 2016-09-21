/*
 * Copyright 2012 Oracle and/or its affiliates.
 * All rights reserved.  You may not modify, use,
 * reproduce, or distribute this software except in
 * compliance with  the terms of the License at:
 * http://developers.sun.com/license/berkeley_license.html
 */


package dukesbookstore.web.managedbeans;

import dukesbookstore.entity.Book;
import java.io.Serializable;
import javax.enterprise.context.SessionScoped;
import javax.inject.Named;


/**
 * <p>Managed bean for the <code>/bookshowcart.xhtml</code> page.</p>
 */
@Named("showcart")
@SessionScoped
public class ShowCartBean extends AbstractBean implements Serializable {
    private boolean isCartChanged = false;

    /**
     * <p>Return the
     * <code>ShoppingCartItem</code> instance from the user request.</p>
     */
    protected ShoppingCartItem item() {
        ShoppingCartItem item = (ShoppingCartItem) context()
                                                       .getExternalContext()
                                                       .getRequestMap()
                                                       .get("item");

        return (item);
    }

    /**
     * <p>Show the details page for the current book.</p>
     */
    public String details() {
        context()
            .getExternalContext()
            .getSessionMap()
            .put(
            "selected",
            item().getItem());

        return ("bookdetails");
    }

    /**
     * <p>Remove the item from the shopping cart.</p>
     */
    public String remove() {
        Book book = (Book) item()
                               .getItem();
        cart.remove(book.getBookId());
        isCartChanged = true;
        message(
            null,
            "ConfirmRemove",
            new Object[] { book.getTitle() });

        return (null);
    }

    /**
     * <p>Update the quantities in the shopping cart, based on the values
     * entered in the "Quantity" column.</p>
     */
    public String update() {
        if (isCartChanged) {
            message(null, "QuantitiesUpdated");
            isCartChanged = false;
        } else {
            message(null, "QuantitiesNotUpdated");
        }

        return (null);
    }
}
