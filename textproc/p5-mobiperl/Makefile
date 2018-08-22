# $NetBSD: Makefile,v 1.15 2018/08/22 09:47:12 wiz Exp $
#

DISTNAME=	mobiperl-0.0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc
# no https support in pkgsrc
MASTER_SITES=	# https://dev.mobileread.com/dist/tompe/mobiperl/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://dev.mobileread.com/trac/mobiperl/wiki
COMMENT=	Tools for generating and manipulating MobiPocket files
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-Palm-[0-9]*:../../databases/p5-Palm
DEPENDS+=	p5-Getopt-Mixed-[0-9]*:../../devel/p5-Getopt-Mixed
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-Image-BMP-[0-9]*:../../graphics/p5-Image-BMP
#DEPENDS+=	{perl>=5.7.3,p5-Encode-[0-9]*}:../../textproc/p5-Encode
DEPENDS+=	p5-XML-Parser-Lite-Tree-[0-9]*:../../textproc/p5-XML-Parser-Lite-Tree
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

INSTALLATION_DIRS=	bin ${PERL5_INSTALLVENDORLIB}/MobiPerl
INSTALLATION_DIRS+=	${PERL5_INSTALLVENDORLIB}/Palm
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PERL=		*mobi*
USE_TOOLS+=		pod2man

do-build:
	cd ${WRKSRC} && \
	pod2man mobi2mobi > mobi2mobi.1; \
	pod2man mobils > mobils.1; \
	pod2man mobi2html > mobi2html.1; \
	pod2man lit2mobi > lit2mobi.1; \
	pod2man opf2mobi > opf2mobi.1; \
	pod2man html2mobi > html2mobi.1

do-install:
	${INSTALL_DATA} ${WRKSRC}/MobiPerl/* ${DESTDIR}${PERL5_INSTALLVENDORLIB}/MobiPerl
	${INSTALL_DATA} ${WRKSRC}/Palm/* ${DESTDIR}${PERL5_INSTALLVENDORLIB}/Palm
.for file in html2mobi lit2mobi mobi2html mobi2mobi mobils opf2mobi
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
