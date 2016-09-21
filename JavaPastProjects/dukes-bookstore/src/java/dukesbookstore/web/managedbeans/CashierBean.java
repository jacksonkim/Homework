/*
 * Copyright 2012 Oracle and/or its affiliates.
 * All rights reserved.  You may not modify, use,
 * reproduce, or distribute this software except in
 * compliance with  the terms of the License at:
 * http://developers.sun.com/license/berkeley_license.html
 */


package dukesbookstore.web.managedbeans;

import dukesbookstore.ejb.BookRequestBean;
import java.io.Serializable;
import java.util.Date;
import javax.ejb.EJB;
import javax.enterprise.context.SessionScoped;
import javax.faces.component.UIOutput;
import javax.faces.component.UISelectBoolean;
import javax.faces.model.SelectItem;
import javax.inject.Named;


/**
 * <p>Managed bean for the
 * <code>/bookcashier.xhtml</code> page.</p>
 */
@Named("cashier")
@SessionScoped
public class CashierBean extends AbstractBean implements Serializable {
    private static SelectItem[] newsletterItems = {
            new SelectItem("200", "Duke's Quarterly"),
            new SelectItem("201", "Innovator's Almanac"),
            new SelectItem("202", "Duke's Diet and Exercise Journal"),
            new SelectItem("203", "Random Ramblings")
        };
    protected Date shipDate;
    protected String creditCardNumber = null;
    protected String name = null;
    protected String shippingOption = "2";
    protected String[] newsletters = new String[0];
    @EJB
    BookRequestBean bookRequestBean;
    UIOutput specialOfferText = null;
    UIOutput thankYou = null;
    UISelectBoolean specialOffer = null;
    private String stringProperty = "This is a String property";

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public String getCreditCardNumber() {
        return creditCardNumber;
    }

    public void setCreditCardNumber(String creditCardNumber) {
        this.creditCardNumber = creditCardNumber;
    }

    public void setNewsletters(String[] newsletters) {
        this.newsletters = newsletters;
    }

    public String[] getNewsletters() {
        return this.newsletters;
    }

    public SelectItem[] getNewsletterItems() {
        return newsletterItems;
    }

    public Date getShipDate() {
        return this.shipDate;
    }

    public void setShipDate(Date shipDate) {
        this.shipDate = shipDate;
    }

    public void setShippingOption(String shippingOption) {
        this.shippingOption = shippingOption;
    }

    public String getShippingOption() {
        return this.shippingOption;
    }

    public UIOutput getSpecialOfferText() {
        return this.specialOfferText;
    }

    public void setSpecialOfferText(UIOutput specialOfferText) {
        this.specialOfferText = specialOfferText;
    }

    public UISelectBoolean getSpecialOffer() {
        return this.specialOffer;
    }

    public void setSpecialOffer(UISelectBoolean specialOffer) {
        this.specialOffer = specialOffer;
    }

    public UIOutput getThankYou() {
        return this.thankYou;
    }

    public void setThankYou(UIOutput thankYou) {
        this.thankYou = thankYou;
    }

    public String getStringProperty() {
        return (this.stringProperty);
    }

    public void setStringProperty(String stringProperty) {
        this.stringProperty = stringProperty;
    }

    public String submit() {
        // Subscribing to newsletters would go here

        // Calculate and save the ship date
        int days = Integer.valueOf(shippingOption)
                          .intValue();
        Date shippingDate = new Date();
        shippingDate = new Date(
                    shippingDate.getTime() + ((long) days * (long) 86400000));
        setShipDate(shippingDate);

        if ((cart.getTotal() > 100.00) && !specialOffer.isRendered()) {
            specialOfferText.setRendered(true);
            specialOffer.setRendered(true);

            return null;
        } else if (specialOffer.isRendered() && !thankYou.isRendered()) {
            thankYou.setRendered(true);

            return null;
        } else {
            try {
                bookRequestBean.updateInventory(cart);
            } catch (Exception ex) {
                return "bookordererror";
            }

            cart.clear();

            return ("bookreceipt");
        }
    }
}