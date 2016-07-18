using UnityEngine;
using System.Collections;

public class GameScene : MonoBehaviour {
    // Use this for initialization
    void Start () {
        for(int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
                cube.transform.position=new Vector3(x, y, 0);
                //Instantiate(cube, new Vector3(x, y, 0), new Quaternion(0, 0, 0, 0));
            }
        }
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
