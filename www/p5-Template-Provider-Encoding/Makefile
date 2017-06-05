# $NetBSD: Makefile,v 1.11 2017/06/05 14:25:32 ryoon Exp $

DISTNAME=		Template-Provider-Encoding-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Template-Provider-Encoding/
COMMENT=		Explicitly declare encodings of your templates

DEPENDS+=		p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Provider/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
