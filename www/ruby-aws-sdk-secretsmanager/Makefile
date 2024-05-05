# $NetBSD: Makefile,v 1.25 2024/05/05 17:27:48 taca Exp $

DISTNAME=	aws-sdk-secretsmanager-1.92.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS SDK for Ruby - AWS Secrets Manager
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-core>=3.191<4:../../www/ruby-aws-sdk-core
#DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=1.1<2:../../www/ruby-aws-sigv4

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
