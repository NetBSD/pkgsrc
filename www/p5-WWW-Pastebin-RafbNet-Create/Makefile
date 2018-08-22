# $NetBSD: Makefile,v 1.11 2018/08/22 09:47:57 wiz Exp $

DISTNAME=	WWW-Pastebin-RafbNet-Create-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Pastebin-RafbNet-Create/
COMMENT=	Create new pastes on http://rafb.net/ from Perl

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/WWW/Pastebin/RafbNet/Create/.packlist

DEPENDS+=	p5-Class-Data-Accessor>=0.04001:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
# LWP::UserAgent 2.036 is really what is required
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
