# $NetBSD: Makefile,v 1.15 2011/08/14 15:14:20 obache Exp $

DISTNAME=	XML-Sablotron-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xsb
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://www.gingerall.com/charlie/ga/xml/p_sab.xml
COMMENT=	Perl interface to the Sablotron XSLT processor
LICENSE=	mpl-1.1 OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

EXPATLIBPATH=	${BUILDLINK_PREFIX.expat}/lib
EXPATINCPATH=	${BUILDLINK_PREFIX.expat}/include
SABLOTLIBPATH=	${BUILDLINK_PREFIX.sablotron}/lib
SABLOTINCPATH=	${BUILDLINK_PREFIX.sablotron}/include

PERL5_PACKLIST=		auto/XML/Sablotron/.packlist

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/sablotron/buildlink3.mk"
.include "../../lang/perl5/module.mk"

post-patch:
	${MV} ${WRKSRC:Q}/Makefile.PL ${WRKSRC:Q}/Makefile.PL.orig
	${SED} \
	-e 's|^\(my \$$expat_libpath = '\''\)\('\'';\)$$|\1${EXPATLIBPATH}\2|' \
	-e 's|^\(my \$$expat_incpath = '\''\)\('\'';\)$$|\1${EXPATINCPATH}\2|' \
	-e 's|^\(my \$$sablot_libpath = '\''\)\('\'';\)$$|\1${SABLOTLIBPATH}\2|' \
	-e 's|^\(my \$$sablot_incpath = '\''\)\('\'';\)$$|\1${SABLOTINCPATH}\2|' \
	${WRKSRC:Q}/Makefile.PL.orig > ${WRKSRC:Q}/Makefile.PL

.include "../../mk/bsd.pkg.mk"
