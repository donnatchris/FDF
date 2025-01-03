PROJECT FDF FOR 42
- By chdonnat (Christophe Donnat from 42 Perpignan, France)

AIM OF THE PROJECT:
This project involves graphically creating the schematic representation of a terrain in relief by connecting different points (x, y, z) with segments.
You must use the MiniLibX, either the version available on the school machines or by installing it from the sources.
The rendering must be displayed using an isometric projection.
The terrain coordinates will be stored in a file provided as a parameter.
Each number represents a point in space:
The horizontal position corresponds to its x-coordinate.
The vertical position corresponds to its y-coordinate.
The value corresponds to its altitude (z-coordinate).
Graphic Management
Your program must display an image in a window.
The window management must remain smooth (switching windows, minimizing, etc.).
Pressing the ESC key must close the window and exit the program cleanly.
Clicking on the close button at the top of the window must close the window and exit the program cleanly.
Using MiniLibX images is mandatory.
BONUS PART:
You will earn additional points if you:
Include an additional projection (e.g., parallel or conical projection).
Implement zoom in and zoom out.
Implement translation (movement).
Implement rotation (rotating your rendering).
Add an extra bonus feature of your choice.

SOME COMMANDS YOU CAN USE:
complete by the aim of the project

ARCHITECTURE:
- src/ directory for main src files
- utils/ directory for secondary files
- bonus/ directory for the bonus files (if any)
- includes/ directory for header files
- test/ directory fot tests files
- libft/ directory with my own library (standard functions, ft_printf, get_next_line)
- minilibx/ directory with a simple X-Window (X11R6) programming API provided with the subject
- Makefile (with rules: make bonus clean fclean re)
- readme.txt for quick explanation and main commands of the project

DOCUMENTATION:
errno
	errno is a global variable defined in <errno.h> that stores an error code set by system calls or library functions when they fail.
	Each error code corresponds to a specific failure reason, such as ENOENT for "No such file or directory" or EACCES for "Permission denied."
	These codes provide a standardized way to identify errors.
	It’s important to check and use errno immediately after a function fails, as its value can be overwritten by subsequent calls.
perror
	perror is a C standard library function used to display an error message associated with the current value of errno.
	It outputs a descriptive string that includes a user-provided message (for context) followed by the error description.
	The format is typically:
	<user message>: <error description>
	For example, if fopen fails to open a file and sets errno to ENOENT, calling perror("File open error") will output:
	File open error: No such file or directory
strerror
	strerror is a C standard library function that converts an error code (typically stored in errno) into a human-readable error message.
	It returns a pointer to a string describing the error corresponding to the given error code.
	For example, if errno is set to ENOENT, calling strerror(ENOENT) would return "No such file or directory".
	This is useful for displaying or manipulating error messages without directly printing them to standard output.
	Difference Between strerror and perror:
		The key difference is that perror directly prints the error message with an optional prefix to standard error (stderr),
		while strerror returns the error message as a string, allowing greater flexibility for formatting or logging.
	Risks of Using strerror:
		strerror is not thread-safe because it may use a static internal buffer to store the returned string.
		This can lead to unexpected results in multi-threaded programs where multiple threads access strerror simultaneously.
		For thread-safe alternatives, use strerror_r.
common errno error codes
	Here are values standardized across UNIX-like systems, including Linux.
	The error codes correspond to specific error conditions that might occur in system calls or library functions,
	such as file handling, memory allocation, and process management.
	Code	Value	Description
	EPERM	1	Operation not permitted
	ENOENT	2	No such file or directory
	ESRCH	3	No such process
	EINTR	4	Interrupted system call
	EIO		5	Input/output error
	ENXIO	6	No such device or address
	E2BIG	7	Argument list too long
	ENOEXEC	8	Exec format error
	EBADF	9	Bad file descriptor
	ECHILD	10	No child processes
	EAGAIN	11	Resource temporarily unavailable
	ENOMEM	12	Out of memory
	EACCES	13	Permission denied
	EFAULT	14	Bad address
	EBUSY	16	Device or resource busy
	EEXIST	17	File exists
	ENODEV	19	No such device
	ENOTDIR	20	Not a directory
	EISDIR	21	Is a directory
	EINVAL	22	Invalid argument
	ENFILE	23	Too many open files in system
	EMFILE	24	Too many open files (per process)
	EFBIG	27	File too large
	ENOSPC	28	No space left on device
	EROFS	30	Read-only file system
	EMLINK	31	Too many links
	EPIPE	32	Broken pipe
	EDOM	33	Math argument out of domain
	ERANGE	34	Result too large
