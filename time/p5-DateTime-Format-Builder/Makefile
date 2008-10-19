# $NetBSD: Makefile,v 1.3 2008/10/19 19:19:00 he Exp $

DISTNAME=	DateTime-Format-Builder-0.7901
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~drolsky/DateTime-Format-Builder/
COMMENT=	Create DateTime parser classes and objects

DEPENDS+=	p5-DateTime>=0.12:../../time/p5-DateTime
PERL5_MODULE_TYPE=   Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/DateTime/Format/Builder/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
