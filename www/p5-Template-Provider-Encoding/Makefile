# $NetBSD: Makefile,v 1.14 2019/08/11 13:25:01 wiz Exp $

DISTNAME=		Template-Provider-Encoding-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Template-Provider-Encoding
COMMENT=		Explicitly declare encodings of your templates

DEPENDS+=		p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Provider/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
