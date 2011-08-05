# $NetBSD: Makefile,v 1.81 2011/08/05 19:38:47 spz Exp $

DISTNAME=	libwww-perl-6.02
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
SVR4_PKGNAME=	p5lww
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libwww-perl/
COMMENT=	Perl5 library for WWW access
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	{perl>=5.10,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64
DEPENDS+=	{perl>=5.10,p5-Net>=1.09}:../../net/p5-Net		# for Net::FTP>=2.58
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
DEPENDS+=	p5-File-Listing>=6.02:../../devel/p5-File-Listing
DEPENDS+=	p5-HTTP-Message>=6.02:../../www/p5-HTTP-Message
DEPENDS+=	p5-HTTP-Cookies>=6.00:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Daemon>=6.00:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-HTTP-Negotiate>=6.00:../../www/p5-HTTP-Negotiate
DEPENDS+=	p5-Net-HTTP>=6.01:../../www/p5-Net-HTTP
DEPENDS+=	p5-WWW-RobotRules>=6.01:../../www/p5-WWW-RobotRules
# it would run without the following, but not do any https then
DEPENDS+=	p5-LWP-Protocol-https>=6.02:../../www/p5-LWP-Protocol-https

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/LWP/.packlist
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
