using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.IO;
using System.Text;

public class BinaryMeshWriter : MonoBehaviour
{
    void Write2DVector(BinaryWriter binaryWriter, Vector2 v)
    {
        binaryWriter.Write(v.x);
        binaryWriter.Write(v.y);
    }

    void Write2DVectors(BinaryWriter binaryWriter, string strName, Vector2[] pVectors)
    {
        binaryWriter.Write(strName);
        binaryWriter.Write(pVectors.Length);
        foreach (Vector2 v in pVectors) Write2DVector(binaryWriter, v);
    }

    void Write3DVector(BinaryWriter binaryWriter, Vector3 v)
    {
        binaryWriter.Write(v.x);
        binaryWriter.Write(v.y);
        binaryWriter.Write(v.z);
    }

    void Write3DVectors(BinaryWriter binaryWriter, string strName, Vector3[] pVectors)
    {
        binaryWriter.Write(strName);
        binaryWriter.Write(pVectors.Length);
        foreach (Vector3 v in pVectors) Write3DVector(binaryWriter, v);
    }

    void WriteIntegers(BinaryWriter binaryWriter, int[] pIntegers)
    {
        binaryWriter.Write(pIntegers.Length);
        foreach (int i in pIntegers) binaryWriter.Write(i);
    }

    void WriteIntegers(BinaryWriter binaryWriter, string strName, int[] pIntegers)
    {
        binaryWriter.Write(strName);
        binaryWriter.Write(pIntegers.Length);
        foreach (int i in pIntegers) binaryWriter.Write(i);
    }

    void WriteBoundingBox(BinaryWriter binaryWriter, string strName, Bounds bounds)
    {
        binaryWriter.Write(strName);
        Write3DVector(binaryWriter, bounds.center);
        Write3DVector(binaryWriter, bounds.extents);
    }

    void WriteSubMeshes(BinaryWriter binaryWriter, string strName, Mesh mesh)
    {
        binaryWriter.Write(strName);
        int nSubMeshes = mesh.subMeshCount;
        binaryWriter.Write(nSubMeshes);
        for (int i = 0; i < nSubMeshes; i++)
        {
            uint nSubMeshStart = mesh.GetIndexStart(i);
            uint nSubMeshIndices = mesh.GetIndexCount(i);
            int[] pSubMeshIndices = mesh.GetIndices(i);
            binaryWriter.Write(nSubMeshStart);
            binaryWriter.Write(nSubMeshIndices);
            WriteIntegers(binaryWriter, pSubMeshIndices);
        }
    }

    void WriteMesh(Mesh mesh, string strObjectName)
    {
        BinaryWriter binaryWriter = new BinaryWriter(File.Open(strObjectName + ".bin", FileMode.Create));

        WriteBoundingBox(binaryWriter, "<BoundingBox>:", mesh.bounds); //AABB

        Write3DVectors(binaryWriter, "<Vertices>:", mesh.vertices);
        Write3DVectors(binaryWriter, "<Normals>:", mesh.normals);
        Write2DVectors(binaryWriter, "<TextureCoords>:", mesh.uv);
        WriteIntegers(binaryWriter, "<Indices>:", mesh.triangles);

        binaryWriter.Flush();
        binaryWriter.Close();
    }

    void Start()
    {
        MeshFilter meshFilter = transform.gameObject.GetComponent<MeshFilter>();
        MeshRenderer meshRenderer = transform.gameObject.GetComponent<MeshRenderer>();

        if (meshFilter && meshRenderer)
        {
            string strObjectName = string.Copy(transform.name).Replace(" ", "_");
            WriteMesh(meshFilter.mesh, strObjectName);
        }

        print("Mesh Write Completed");
    }
}
