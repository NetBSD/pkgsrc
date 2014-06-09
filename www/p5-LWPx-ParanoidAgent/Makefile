# $NetBSD: Makefile,v 1.12 2014/06/09 20:08:15 schmonz Exp $
#

DISTNAME=	LWPx-ParanoidAgent-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWPx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWPx-ParanoidAgent/
COMMENT=	Subclass of module LWP::UserAgent that protects you from harm
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

PERL5_PACKLIST=		auto/LWPx/ParanoidAgent/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
