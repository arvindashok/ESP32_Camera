import face_recognition
import cv2
import os


# Function to load all images from a directory and encode faces
def load_images_and_encodings(directory):
    known_faces = {}

    for person_folder in os.listdir(directory):
        person_path = os.path.join(directory, person_folder)
        
        if os.path.isdir(person_path):
            # For each person, create a list to store face encodings
            person_encodings = []

            for filename in os.listdir(person_path):
                if filename.endswith(".jpg") or filename.endswith(".png"):
                    image_path = os.path.join(person_path, filename)
                    image = face_recognition.load_image_file(image_path)
                    face_encoding = face_recognition.face_encodings(image)[0]
                    
                    person_encodings.append(face_encoding)

            # Use the person's name (folder name) as the key in the dictionary
            known_faces[person_folder] = person_encodings

    return known_faces

# Specify the directory containing folders for each person
known_faces_directory = "Faces"

# Load known faces and their encodings
known_faces = load_images_and_encodings(known_faces_directory)

# Load the image to be recognized
unknown_image = face_recognition.load_image_file("im1.jpg")

# Find faces in the unknown image
face_locations = face_recognition.face_locations(unknown_image)
face_encodings = face_recognition.face_encodings(unknown_image, face_locations)

# Initialize OpenCV window
cv2_image = cv2.imread("im1.jpg")

for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
    name = "Unknown"

    # Check if the face matches any known faces
    for known_name, known_encodings in known_faces.items():
        matches = face_recognition.compare_faces(known_encodings, face_encoding)
        if True in matches:
            name = known_name
            break

    # Draw rectangle and label on the image
    cv2.rectangle(cv2_image, (left, top), (right, bottom), (0, 255, 0), 2)
    font = cv2.FONT_HERSHEY_DUPLEX
    cv2.putText(cv2_image, name, (left + 6, bottom - 6), font, 0.5, (255, 255, 255), 1)

# Display the result
cv2.imshow('Face Recognition', cv2_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
