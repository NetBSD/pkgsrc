# $NetBSD: Makefile,v 1.1 2014/09/04 22:01:35 markd Exp $

DISTNAME=		WWW-CSRF-1.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=WWW/}
LICENSE=		${PERL5_LICENSE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/WWW-CSRF/
COMMENT=		Generate and check tokens to protect against CSRF attacks

DEPENDS+=		p5-Bytes-Random-Secure>=0.26:../../security/p5-Bytes-Random-Secure
DEPENDS+=		p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC

PERL5_PACKLIST=		auto/WWW/CSRF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
