import React from "react";
import { View, Button, Alert } from "react-native";

export default Alerta = () => {
  const showAlert = () => {
    Alert.alert("ALERTA", "boa noite", [
      { text: "sim", onPress: () => console.warn("boa noite") },
      { text: "não", onPress: () => console.warn("não boa noite") },
    ]);
  };

  return (
    <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
      <Button title="alerta" onPress={showAlert}></Button>
    </View>
  );
};
