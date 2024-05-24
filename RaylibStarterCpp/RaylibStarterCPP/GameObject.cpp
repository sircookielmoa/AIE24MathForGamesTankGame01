#include "GameObject.h"

void GameObject::OnUpdate(float deltaTime)
{

}

void GameObject::OnDraw()
{
}

GameObject::GameObject()
{
    // IMPORTANT: Set LocalPosition.Z to 1 to ensure children will inherit translations
    Parent = nullptr;
    LocalPosition = MathClasses::Vector3(0, 0, 1);
    LocalRotation = 0;
    LocalScale = MathClasses::Vector3(1, 1, 1);
}

void GameObject::Update(float deltaTime)
{
    OnUpdate(deltaTime);
    for (auto& child :Children)
    {
        child->Update(deltaTime);
    }
    // TODO: iterate through children and call Update on them
}

void GameObject::Draw()
{
    OnDraw();
    for (auto& child : Children)
    {
        child->Draw();
    }

    // TODO: iterate through children and call Draw on them
}

void GameObject::SetParent(GameObject* newParent)
{
    // remove from existing parent if any
    if (Parent != nullptr)
    {
        // returns an iterator to this child in its parent's vector of children
        auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

        // if found, iterator will be something besides the end of the vector
        if (findIt != Parent->Children.end())
        {
            Parent->Children.erase(findIt);
            Parent = nullptr;
        }
    }

    // add to new parent if any
    if (newParent != nullptr)
    {
        Parent = newParent;
        Parent->Children.push_back(this);
    }
}

GameObject* GameObject::GetParent()
{
    return Parent;
}

const GameObject* GameObject::GetParent() const
{
    return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
    return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
    return Children[childIndex];
}

MathClasses::Vector3 GameObject::GetLocalPosition() const
{
    return LocalPosition;
}

void GameObject::SetLocalPosition(MathClasses::Vector3 newPosition)
{
    LocalPosition = newPosition;
}

void GameObject::SetLocalPosition(float newX, float newY)
{
    LocalPosition = MathClasses::Vector3(newX, newY, LocalPosition.z);
}

MathClasses::Vector3 GameObject::GetWorldPosition() const
{
    MathClasses::Matrix3 worldMat = GetWorldMatrix();
    return MathClasses::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetLocalRotation() const
{
    return LocalRotation;
}

void GameObject::SetLocalRotation(float newRotation)
{
    LocalRotation = newRotation;
}

float GameObject::GetWorldRotation() const
{
    MathClasses::Vector3 fwd = GetForward();
    return fwd.AngleFrom2D();
}

MathClasses::Vector3 GameObject::GetLocalScale() const
{
    return LocalScale;
}

void GameObject::SetLocalScale(MathClasses::Vector3 newScale)
{
    LocalScale = newScale;
}

void GameObject::SetLocalScale(float newX, float newY)
{
    LocalScale = MathClasses::Vector3(newX, newY, LocalScale.z);
}

MathClasses::Vector3 GameObject::GetWorldScale() const
{
    // calculate the local transform matrix
    MathClasses::Matrix3 myTransform = GetWorldMatrix();

    return MathClasses::Vector3(MathClasses::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(),
        MathClasses::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(),
        1.0f);
}

MathClasses::Vector3 GameObject::GetForward() const
{
    auto mat = GetWorldMatrix();
    return MathClasses::Vector3(mat[0], mat[1], mat[2]);
}

MathClasses::Matrix3 GameObject::GetLocalMatrix() const
{
    return
        MathClasses::Matrix3::MakeTranslation(LocalPosition) *
        MathClasses::Matrix3::MakeRotateZ(LocalRotation) *
        MathClasses::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

MathClasses::Matrix3 GameObject::GetWorldMatrix() const
{
    // no parent - use as-is
    if (Parent == nullptr)
    {
        return GetLocalMatrix();
    }
    // combine w/ parent's world
    else
    {
        return Parent->GetWorldMatrix() * GetLocalMatrix();
    }
}

void GameObject::Translate(float x, float y)
{
    LocalPosition = LocalPosition + MathClasses::Vector3(x, y, 0);
}

void GameObject::Translate(MathClasses::Vector3 translation)
{
    LocalPosition = LocalPosition + translation;
}

void GameObject::Rotate(float radians)
{
    LocalRotation = LocalRotation + radians;
}

void GameObject::Scale(float x, float y)
{
    LocalScale = LocalScale * MathClasses::Vector3(x, y, 1);
}

void GameObject::Scale(MathClasses::Vector3 scalar)
{
    LocalScale = LocalScale * scalar;
}
