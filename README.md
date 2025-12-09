# Smart Street-Lighting Automation Using LDR Sensors  
### A Low-Cost, Scalable Energy-Saving Solution for Ahilyanagar  
**Created by:** Onkar  
**Location:** Pipeline Road, Dyaneshwar Nagar, Savedi, Ahilyanagar

---

## 📌 Project Overview  
This project proposes and demonstrates a **low-cost LDR (Light-Dependent Resistor) based automatic street-light control system** designed for municipal use.  
It was inspired by real issues in Ahilyanagar, where street lights often:

- Stay ON during daytime  
- Turn ON late during early-dark or monsoon days  
- Depend entirely on manual switching  

The solution uses a **simple Arduino+LDR+Relay** setup to automatically turn lights ON at dusk and OFF at sunrise.

---

## 🎯 Objectives  

- Reduce unnecessary **electricity wastage**  
- Provide **reliable automatic switching**  
- Lower **manual workload** for Municipal corporation & MSEB  
- Increase **public safety** during low-light hours  
- Present a **scalable, low-cost alternative** for rural and semi-urban India  

---

## 🧩 System Architecture  

### **Cluster-Based Lighting Control**  
One LDR + Arduino controller can handle **10–15 streetlights** simultaneously, reducing cost and maintenance.

**Pros:**  
- Very cost-effective  
- Easy to install and maintain  
- Ideal for uniform localities like Savedi  

**Cons:**  
- Controller failure affects all lights in the cluster  
- Minor light differences may affect sensitivity  

---

## 🛠️ Hardware Components  

| Component | Description |
|----------|-------------|
| Arduino Uno / Nano | Main controller |
| LDR | Detects ambient light |
| 10kΩ Resistor | Forms voltage divider |
| Relay Module (5V) | Controls AC street light circuit |
| Connecting wires | For circuit |
| Waterproof enclosure | To protect electronics |

---

## 📡 Working Principle  
1. LDR detects ambient light  
2. Arduino reads analog voltage  
3. If below threshold → street lights **ON**  
4. If above threshold → street lights **OFF**  
5. Works automatically year-round  

---

## 💡 Demo Arduino Code (`ldr_streetlight.ino`)

```cpp
// Smart Street Light Automation - LDR + Relay
// Demo code for project portfolio

int ldr = A0;           // LDR input pin
int relayPin = 7;       // Relay control pin
int threshold = 500;    // Adjust based on environment

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Assume LOW = OFF
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldr);
  Serial.println(ldrValue);

  if (ldrValue < threshold) {
    digitalWrite(relayPin, HIGH); // Turn ON streetlights
  } else {
    digitalWrite(relayPin, LOW);  // Turn OFF streetlights
  }

  delay(500);
}
```

---

## 📈 Block Diagram  

```
LDR → Arduino → Relay Module → AC Street Lights
```

---

## 🌍 Locality & Real-World Relevance  
This project originates from **Ahilyanagar**, specifically **Pipeline Road, Dyaneshwar Nagar, Savedi**, where the community frequently experiences:

- Daytime lights left ON  
- Delayed switching during cloudy monsoon evenings  

This solution addresses **real civic problem with measurable impact**.

---

## 🎓 Why This Project Strengthens MIT Application  

- Shows **initiative** in solving a real local civic issue  
- Demonstrates **engineering + embedded systems** understanding  
- Clear **social impact** and energy-efficiency relevance  
- Shows **end-to-end execution**: observation → design → prototype → documentation  
- Complements AQI + sustainability-focused projects  

---

## 📁 Repository Structure (Recommended)

```
root/
│
├── README.md
├── proposal/
Smart_Street_Light_Project_Onkar.pdf
├── hardware-demo/
│   └── ldr_streetlight.ino
├── diagrams/
│   └── block_diagram.png (optional)
└── images/
    └── setup_photo.jpg (if you add later)
```

---

## 🚀 Future Improvements  
- Add GSM/IoT notifications  
- Add weather-compensation algorithm  
- Implement solar-powered street-light modules  
- Integrate AQI prediction with adaptive brightness## 📬 Contact / Credits  
Created by **Onkar**  
Ahilyanagar, Maharashtra  
For sustainability, civic improvement & MIT application portfolio
