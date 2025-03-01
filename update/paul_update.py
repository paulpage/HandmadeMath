"""
Run this script to:
- Remove HMM_ in most places
- Make functions snake_case instead of PascalCase
- Make most struct fields lowercase

The above changes will be appied in-place to HandmadeMath.h, as well as all
tests.
"""

import os

EXTENSIONS = ('.c', '.cpp', '.h', 'Makefile', '.bat')

# Don't remove HMM_ from these
EXCEPTIONS = [
    'HMM_SINF',
    'HMM_COSF',
    'HMM_TANF',
    'HMM_SQRTF',
    'HMM_ACOSF',
    'HMM_ANGLE_USER_TO_INTERNAL',
    'HMM_ANGLE_INTERNAL_TO_USER',
    'HMM_DEPRECATED',
]

# Make all struct fields lowercase
FIELDS = [
    'X',
    'Y',
    'Z',
    'W',
    'XY',
    'YZ',
    'ZW',
    'XYZ',
    'XYZW',
    'U',
    'V',
    'UV',
    'VW',
    'R',
    'G',
    'B',
    'Left',
    'Right',
    'Width',
    'Height',
    'Elements',
    'Columns',
    # 'SSE',  # If I really wanted to lowercase this I'd have to add logic to
              # not lowercase "SSE.h"
]

# PascalCase -> camel_case
SIMPLE_FUNCS = [
    'ToRad',
    'ToDeg',
    'ToTurn',
    'RadToDeg',
    'RadToTurn',
    'DegToRad',
    'DegToTurn',
    'TurnToRad',
    'TurnToDeg',
    'AngleRad',
    'AngleDeg',
    'AngleTurn',
    'Lerp',
    'Clamp',
    # 'V2',  # I'm not lowercasing these because:
    # 'V3',  #   1. They kinda make sense uppercase since they're kinda like
    # 'V4',  #      shorthand for a type name
    # 'M2',  #   2. (the real reason) They're just a bit too invasive, like
    # 'M3',  #      I'm probably gonna want to have a variable called "v2"
    # 'M4',  #      at some point
    'InvOrthographic',
    'Translate',
    'InvTranslate',
    'InvRotate',
    'Scale',
    'InvScale',
    'InvLookAt',
]

# Replace one with the other
SPECIAL_FUNCS = {
    'SinF': 'm_sin',
    'CosF': 'm_cos',
    'TanF': 'm_tan',
    'ACosF': 'm_acos',
    'SqrtF': 'm_sqrt',
    'InvSqrtF': 'invsqrt',
    # 'V4V': 'v4v',
    # 'QV4': 'qv4',
    # 'Q': 'quat',
    # 'InvQ': 'invq',
    # 'M2D': 'm2d',
    # 'M3D': 'm3d',
    # 'M4D': 'm4d',
    'LinearCombineV4M4': 'linear_combine_v4m4',
    'Orthographic_RH_NO': 'orthographic_rh_no',
    'Orthographic_RH_ZO': 'orthographic_rh_zo',
    'Orthographic_LH_NO': 'orthographic_lh_no',
    'Orthographic_LH_ZO': 'orthographic_lh_zo',
    'Perspective_RH_NO': 'perspective_rh_no',
    'Perspective_RH_ZO': 'perspective_rh_zo',
    'Perspective_LH_NO': 'perspective_lh_no',
    'Perspective_LH_ZO': 'perspective_lh_zo',
    'InvPerspective_RH': 'inv_perspective_rh',
    'InvPerspective_LH': 'inv_perspective_lh',
    'Rotate_RH': 'rotate_rh',
    'Rotate_LH': 'rotate_lh',
    'LookAt_RH': 'look_at_rh',
    'LookAt_LH': 'look_at_lh',
    'QToM4': 'q_to_m4',
    'M4ToQ_RH': 'm4_to_q_rh',
    'M4ToQ_LH': 'm4_to_q_lh',
    'QFromAxis:ngle_RH': 'q_from_axis_angle_rh',
    'QFromAxisAngle_LH': 'q_from_axis_angle_lh',
}

# PascalCase -> camel_case, but for anything starting with these
GENERIC_FUNCS = [
    'Add',
    'Sub',
    'Mul',
    'Div',
    'Len',
    'LenSqr',
    'Norm',
    'Dot',
    'Lerp',
    'Eq',
    'Transpose',
    'Determinant',
    'InvGeneral',
    'Cross',
]

# Mostly I don't care if local variables are uppercase, but some of them
# conflict with the de-HMM_'d types, so lowercase them
VARS = [
    'Quat',
    'Q',
]

# Make these local variables uppercase so they don't conflict with the newly
# lowercased function names
BACKWARDS_VARS = [
    # 'v2',
    # 'v3',
    # 'v4',
    # 'v4v',
    'scale',
    'translate',
    # 'm2',
    # 'm2d',
    # 'm3',
    # 'm3d',
    # 'm4',
    # 'm4d',
]

def tokenize(data):
    tokens = []
    t = ''
    for c in data:
        if c.isalnum() or c == '_':
            t += c
        else:
            if t != '':
                tokens.append(t)
            tokens.append(c)
            t = ''
    return tokens


def replace_token(token):

    if 'HMM_' in token and token not in EXCEPTIONS:

        token = token.replace('HMM_', '')

        if token in SIMPLE_FUNCS:
            new = token[0].lower()
            for c in token[1:]:
                new += '_' + c.lower() if c.isupper() else c
            return new

        if token in SPECIAL_FUNCS:
            return SPECIAL_FUNCS[token]

        for pattern in GENERIC_FUNCS:
            if pattern in token:
                if pattern == token:
                    return pattern.lower()
                else:
                    return pattern.lower() + '_' + token.replace(pattern, '').lower()

        return token.replace('HMM_', '')

    if token in FIELDS:
        return token.lower()

    if token in VARS:
        return token.lower()

    if token in BACKWARDS_VARS:
        return token.upper()

    if token == 'HandmadeMath':
        return 'handmade_math'

    return token


def update_file(filename):

    result = ''

    with open(filename, 'r') as f:
        for token in tokenize(f.read()):
            result += replace_token(token)

    with open(filename, 'w') as f:
        f.write(result)


for root, dirs, files in os.walk('.'):
    for filename in files:
        if filename.endswith(EXTENSIONS):
            update_file(os.path.join(root, filename))

# Yep, really
os.rename('HandmadeMath.h', 'handmade_math.h')

# Rename these too because it's easier than changing my tokenizer
os.rename('test/HandmadeMath.c', 'test/handmade_math.c')
os.rename('test/HandmadeMath.cpp', 'test/handmade_math.cpp')
