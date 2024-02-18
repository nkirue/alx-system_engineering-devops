

Issue Summary:
Commencing at 9:21 PM (WAT) on February 24th, 15, and concluding at 10:51 PM (WAT), our server experienced a total downtime of 1 hour and 30 minutes. During this period, the Wordpress page returned a 500 status code, rendering it inaccessible to all users, constituting 100% downtime.
Root Cause Identification: The primary cause of the issue stemmed from a typographical error in a Wordpress settings document.
Affected User : The incident affected 100% of our user.
Timeline:
February 24th, 15, 9:21 PM (WAT): Multiple users reported the issue to our customer service department.
February 24th, 15, 9:32 PM (WAT): The issue was escalated successively to the Application Support Team and the Software Engineering team.
February 24th, 15, 9:46 PM (WAT): Team members inspected running processes on the server using 'ps auxf' to identify any extraneous child processes hindering server responsiveness.
February 24th, 15, 10:15 PM (WAT): Following a check on running processes, the team employed 'strace' on several process IDs, including those of apache2, the web server hosting the Wordpress page.
February 24th, 15, 10:25 PM (WAT): An infinite loop of system calls was observed during 'strace' on one of the apache2 processes, prompting examination of the second apache2 process.
February 24th, 15, 10:30 PM (WAT): While using 'curl' on the page's IP and running 'strace' on the second apache2 process, the team encountered numerous errors, including one indicating the nonexistence of 'index.html', which proved to be a misleading clue.
February 24th, 15, 10:40 PM (WAT): Upon thorough scrutiny of 'strace' errors, the team identified a file with a '.phpp' extension that apache2 was attempting to access, an uncommon file extension.
February 24th, 15, 10:48 PM (WAT): Inspection of the Wordpress settings file, specifically /var/www/html/wp-settings.php, unveiled a typo at line 137, wherein an erroneous file extension was referenced. The team promptly rectified the error by removing the extra 'p' from the extension.
February 24th, 15, 10:51 PM (WAT): Following the correction, a simple 'service apache2 restart' restored the page's functionality to normalcy.
Root Cause and Resolution:
The root cause of the issue was traced to a single typographical error within the Wordpress settings file, impairing apache2 functionality. Resolution was achieved by rectifying the typo and restarting apache2.
Corrective and Preventative Measures:
To mitigate the risk of similar incidents, it is imperative to restrict write permissions on setting files solely to the Software Engineering team. This precautionary measure aims to prevent inadvertent injection of typographical errors like the one encountered in this incident.
TODO:
Modify permissions on /var/www/html/wp-settings.php to read-only for the team.
Conduct a thorough review of all setting files to detect and rectify any similar typographical errors.
