# $NetBSD: Makefile,v 1.12 2006/03/04 21:31:05 jlam Exp $

DISTNAME=	EasyImage15
PKGREVISION=	3
PKGNAME=	zope25-EasyImage-1.5
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/regebro/easyimage/
EXTRACT_SUFX=	.zip

BUILDLINK_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/regebro/easyimage
COMMENT=	Image extension for Zope

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
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
