# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:27 tv Exp $

DISTNAME=	EasyImage15
PKGREVISION=	2
PKGNAME=	zope25-EasyImage-1.5
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/regebro/easyimage/
EXTRACT_SUFX=	.zip

BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/regebro/easyimage
COMMENT=	Image extension for Zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short
USE_BUILDLINK3=	yes

post-extract:
	${RM} -r ${WRKSRC}/easyimage/cvs ${WRKSRC}/easyimage/icons/cvs \
		${WRKSRC}/easyimage/dtml/cvs
	${MV} ${WRKSRC}/easyimage ${WRKSRC}/EasyImage
	${MV} ${WRKSRC}/EasyImage/easyimage.py ${WRKSRC}/EasyImage/EasyImage.py
	${MV} ${WRKSRC}/EasyImage/icons/easyimage.gif \
		${WRKSRC}/EasyImage/icons/EasyImage.gif
	${MV} ${WRKSRC}/EasyImage/dtml/manage_addeasyimageform.dtml \
		${WRKSRC}/EasyImage/dtml/manage_addEasyImageForm.dtml
	${MV} ${WRKSRC}/EasyImage/dtml/manage_editeasyimageform.dtml \
		${WRKSRC}/EasyImage/dtml/manage_editEasyImageForm.dtml
	${MV} ${WRKSRC}/EasyImage/dtml/manage_convertresizeeasyimageform.dtml \
		${WRKSRC}/EasyImage/dtml/manage_convertResizeEasyImageForm.dtml

.include "../../www/zope25/product.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
