# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 18:10:17 drochner Exp $

DISTNAME=	EasyImage15
PKGNAME=	zope25-EasyImage-1.5
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/regebro/easyimage/
EXTRACT_SUFX=	.zip

BUILDLINK_DEPENDS.pyimaging= ${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/regebro/easyimage
COMMENT=	image extension for Zope

ZOPE_COPYPRODUCT= zope-std-copyproduct-short

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
.include "../../graphics/py-imaging/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
