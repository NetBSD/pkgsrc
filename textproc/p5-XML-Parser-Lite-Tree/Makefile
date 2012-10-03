# $NetBSD: Makefile,v 1.5 2012/10/03 21:58:11 wiz Exp $

DISTNAME=	XML-Parser-Lite-Tree-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Parser/
COMMENT=	Perl extension for a lightweight XML tree builder
LICENSE=	(${PERL5_LICENSE}) AND artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/Parser/Lite/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
