class CarDealer:
    def __init__(self, address, city, id, lat, long, st, zip, full_name, short_name):
        # Dealer address
        self.address = address
        # Dealer city
        self.city = city
        # Dealer id
        self.id = id
        # Location lat
        self.lat = lat
        # Location long
        self.long = long
        # Dealer state
        self.st = st
        # Dealer zip
        self.zip = zip
        # Full name
        self.full_name = full_name
        self.short_name = short_name

    def __str__(self):
        return "Dealer name: " + self.full_name
