# $NetBSD: Makefile,v 1.6 2013/05/31 12:42:51 wiz Exp $

DISTNAME=		Template-Provider-Encoding-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Template-Provider-Encoding/
COMMENT=		Explicitly declare encodings of your templates

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Provider/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
