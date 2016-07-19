using UnityEngine;
using System.Collections;

public class GameCamera : MonoBehaviour
{
    public GameObject player;
    // Use this for initialization
    void Start () {
        player.transform.position = new Vector3(0, 35.5f, 0);
	}
	
	// Update is called once per frame
	void Update () {
        transform.position = new Vector3(player.transform.position.x, player.transform.position.y, player.transform.position.z - 10);
    }
}
