import React from "react";
import { Text, StyleSheet, View, Button } from "react-native";

export default (props) => {
  return (
    <View style={[styles.tela, { backgroundColor: "red" }]}>
      <Text style={[{ fontSize: 50, color: "#FFF" }]}>Tela A</Text>
      <Button
        title="IR PARA TELA A"
        onPress={() => props.navigation.navigate("TelaA")}
      ></Button>
    </View>
  );
};

const styles = StyleSheet.create({
  tela: {
    flex: 1,

    justifyContent: "center",

    alignItems: "center",
  },
});
