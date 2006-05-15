# $NetBSD: Makefile,v 1.1.1.1 2006/05/15 12:02:34 markd Exp $

DISTNAME=	LWP-Authen-Negotiate-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://perlgssapi.sourceforge.net/
COMMENT=	Library for enabling GSSAPI authentication in LWP

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-GSSAPI-[0-9]*:../../security/p5-GSSAPI
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/LWP/Authen/Negotiate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
