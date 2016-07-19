using UnityEngine;
using System.Collections;

public class GameCamera : MonoBehaviour {
    public GameObject player;
    private float speedX, speedY;
    // Use this for initialization
    void Start () {
        player.transform.position = new Vector3(0, 35.5f, 0);
        speedX = 0;
        speedY = 0;
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.A))
        {
            speedX -= Time.deltaTime * 10;
        }
        if (Input.GetKey(KeyCode.D))
        {
            speedX += Time.deltaTime * 10;
        }
        if (Input.GetKey(KeyCode.Space))
        {
            speedY += Time.deltaTime * 10;
        }
        player.transform.position = new Vector3(player.transform.position.x+speedX, player.transform.position.y+speedY, player.transform.position.z);
        transform.position = new Vector3(player.transform.position.x, player.transform.position.y, player.transform.position.z - 10);
        if(speedX>0) speedX--;
        if (speedX < 0) speedX = 0;
        if (speedY>0)speedY--;
        if (speedY < 0) speedY = 0;
    }

    void OnTriggerEnter(Collider collisionInfo)
    {
        Debug.Log("碰撞到的物体的名字是：" + collisionInfo.gameObject.name);
    }
}
