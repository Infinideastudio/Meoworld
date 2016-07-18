using UnityEngine;
using System.Collections;

public class Gravity : MonoBehaviour {

    public float dropSpeed;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
        transform.position = new Vector3(transform.position.x, transform.position.y + Time.deltaTime * dropSpeed*-1, transform.position.z);
	}
}
