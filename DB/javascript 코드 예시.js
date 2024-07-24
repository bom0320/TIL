const db = firebase.firestore();

// 일기 컬렉션에 새 문서 추가
db.collection("diaries").add({
    title: "My First Diary",
    content: "Today was a good day!",
    created_at: firebase.firestore.FieldValue.serverTimestamp()
})
.then((docRef) => {
    console.log("Document written with ID: ", docRef.id);
})
.catch((error) => {
    console.error("Error adding document: ", error);
});

// 일기 컬렉션에서 문서 조회
db.collection("diaries").get().then((querySnapshot) => {
    querySnapshot.forEach((doc) => {
        console.log(`${doc.id} => ${doc.data().title}`);
    });
});

