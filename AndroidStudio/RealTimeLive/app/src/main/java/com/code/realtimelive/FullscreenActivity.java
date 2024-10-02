package com.code.realtimelive;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Size;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.camera.core.CameraSelector;
import androidx.camera.core.Preview;
import androidx.camera.lifecycle.ProcessCameraProvider;
import androidx.camera.view.PreviewView;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.util.concurrent.ExecutionException;

public class FullscreenActivity extends AppCompatActivity {

    private static final int REQUEST_CAMERA_PERMISSION = 100;

    private PreviewView previewView;
    private LinearLayout reactionLayout;
    private TextView textViewLikeCount; // Declare textViewLikeCount here

    private int likeCount = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fullscreen);

        // Initialize UI elements
        previewView = findViewById(R.id.previewView);
        reactionLayout = findViewById(R.id.reactionLayout);
        textViewLikeCount = findViewById(R.id.textViewLikeCount); // Initialize textViewLikeCount

        // Request camera permissions if not granted
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CAMERA}, REQUEST_CAMERA_PERMISSION);
        } else {
            try {
                startCamera();
            } catch (ExecutionException | InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        // Set click listeners for reaction buttons
        reactionLayout.findViewById(R.id.buttonThumbsUp).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Simulate a thumbs-up reaction
                likeCount++;
                updateLikeCount();
            }
        });

        reactionLayout.findViewById(R.id.buttonHeart).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Simulate a heart reaction
                likeCount++;
                updateLikeCount();
            }
        });
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

        if (requestCode == REQUEST_CAMERA_PERMISSION) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                try {
                    startCamera();
                } catch (ExecutionException | InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }

    private void startCamera() throws ExecutionException, InterruptedException {
        // Create a CameraProvider instance
        ProcessCameraProvider cameraProvider = ProcessCameraProvider.getInstance(this).get();

        // Create a CameraSelector instance for the back camera
        CameraSelector cameraSelector = new CameraSelector.Builder()
                .requireLensFacing(CameraSelector.LENS_FACING_BACK)
                .build();

        // Create a Preview instance
        Preview preview = new Preview.Builder()
                .setTargetResolution(new Size(640, 480))
                .build();

        // Bind the Preview to the PreviewView
        preview.setSurfaceProvider(previewView.getSurfaceProvider());

        // Bind the Preview to the CameraProvider
        cameraProvider.bindToLifecycle(this, cameraSelector, preview);
    }

    private void updateLikeCount() {
        textViewLikeCount.setText("Likes: " + likeCount);
    }
}
