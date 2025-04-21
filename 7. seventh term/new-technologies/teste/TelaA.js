import React from "react";
import { Text, StyleSheet, View, Button } from "react-native";

export default (props) => {
  return (
    <View style={[styles.tela, { backgroundColor: "green" }]}>
      <Text style={[{ fontSize: 50, color: "#FFF" }]}>Tela A</Text>
      <Button
        title="IR PARA TELA B"
        onPress={() => props.navigation.navigate("TelaB")}
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
