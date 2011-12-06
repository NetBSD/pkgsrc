# $NetBSD: Makefile,v 1.5 2011/12/06 06:50:04 hiramatsu Exp $

DISTNAME=	Dancer-1.3080
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/X/XS/XSAWYERX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perldancer.org/
COMMENT=	Perl 5 lightweight yet powerful web application framework
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Dancer/.packlist

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Body-[0-9]*:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Server-Simple-PSGI>=0.11:../../www/p5-HTTP-Server-Simple-PSGI
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-Test-Simple>=0.87:../../devel/p5-Test-Simple
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
