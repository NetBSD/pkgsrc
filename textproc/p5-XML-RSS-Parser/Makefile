# $NetBSD: Makefile,v 1.14 2011/08/14 15:14:19 obache Exp $

DISTNAME=	XML-RSS-Parser-4.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Liberal object-oriented parser for RSS feeds

DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Elemental>=2.0:../../textproc/p5-XML-Elemental
DEPENDS+=	p5-Class-XPath>=1.4:../../devel/p5-Class-XPath
DEPENDS+=	p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/XML-RSS-Parser-4

PERL5_PACKLIST=		auto/XML/RSS/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
