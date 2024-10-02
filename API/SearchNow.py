import webbrowser

def searchGoogle(query):
    query = query.replace("google", "")
    webbrowser.open_new_tab(f"https://www.google.com/search?q={query}")

def searchYoutube(query):
    query = query.replace("youtube", "")
    webbrowser.open_new_tab(f"https://www.youtube.com/results?search_query={query}")

def searchWikipedia(query):
    query = query.replace("wikipedia", "")
    webbrowser.open_new_tab(f"https://en.wikipedia.org/wiki/{query}")

if __name__ == "__main__":
    # Test cases
    searchGoogle("google how to make pizza")
    searchYoutube("youtube funny cat videos")
    searchWikipedia("wikipedia artificial intelligence")
    
