# $NetBSD: Makefile,v 1.14 2011/08/14 15:14:19 obache Exp $

DISTNAME=	XML-RAI-1.3031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Maps RSS tags to one common simplified interface
HOMEPAGE=	http://search.cpan.org/dist/XML-RAI/
LICENSE=	artistic

DEPENDS+=	p5-Task-Weaken>=1.02:../../devel/p5-Task-Weaken
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-XML-RSS-Parser>=4.0:../../textproc/p5-XML-RSS-Parser

BUILD_DEPENDS+=	p5-Test-Weaken-[0-9]*:../../devel/p5-Test-Weaken

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/RAI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
